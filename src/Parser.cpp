#include "Parser.hpp"
#include "IResult.hpp"
#include "Attribute.hpp"
#include "Data.hpp"
#include "XmlElementInterpreter.hpp"
#include "MultiLineAccumulator.hpp"
#include "XmlOpeningElementInterpreter.hpp"
#include "XmlClosingElementInterpreter.hpp"
#include "XmlCommentElementInterpreter.hpp"
#include "XmlElementContentsInterpreter.hpp"
#include "XmlEmptyElementInterpreter.hpp"
#include "XmlLine.hpp"

#include <iostream>

Parser::Parser(const std::string& filename)
{
  _fstream.open(filename.c_str(), std::fstream::in); 
}

Parser::~Parser()
{
  _fstream.close(); 
}

bool Parser::parse(IResult* result)
{
  std::vector<XmlElementInterpreter*> interpreters;
  prepareInterpreters(interpreters, result);

  MultiLineAccumulator accumulator;

  std::string line;
  while(std::getline(_fstream, line))
  {
    std::cout << "\n\n\n|" << line << "|" << std::endl;
    std::string str = trim(line);
    printf("trimmed line:%s<--\n", str.c_str());

    accumulator.tryToMerge(str);
    if (accumulator.isMergeInProgress())
      continue;
    if (accumulator.isMergeFinished())
    {
      str = accumulator.getMerged();
      accumulator.reset();
    }

    size_t start = 0;
    XmlLine xmlLine(str, start);

    do
    {
      for(size_t i=0; i<interpreters.size(); ++i)
      {
        if (interpreters[i]->interpret(&xmlLine) == XmlElementInterpreter::ERROR)
        {
          std::cout << "XML INVALID!" << std::endl;
          return false;
        }
        start = xmlLine.getCurrIndex();
        if (xmlLine.isAtEnd())
          break;
      }
    } while (!xmlLine.isAtEnd());
  }
  return true;
}

std::string Parser::trim(const std::string& str)
{
  size_t start = str.find_first_not_of(' ');
  size_t end = str.find_last_not_of(' ');
  if (end == std::string::npos)
    end = str.length() - 1;
  return str.substr(start, end-start);
}

void Parser::prepareInterpreters(std::vector<XmlElementInterpreter*>& interpreters, IResult* result)
{
  interpreters.push_back(new XmlCommentElementInterpreter(result, &_validation));
  interpreters.push_back(new XmlOpeningElementInterpreter(result, &_validation));
  interpreters.push_back(new XmlElementContentsInterpreter(result, &_validation));
  interpreters.push_back(new XmlClosingElementInterpreter(result, &_validation));
  interpreters.push_back(new XmlEmptyElementInterpreter(result, &_validation));
}

void Parser::deleteInterpreters(std::vector<XmlElementInterpreter*>& interpreters) const
{
  for (std::vector<XmlElementInterpreter*>::iterator it = interpreters.begin(); it != interpreters.end(); ++it)
    delete *it;
}
