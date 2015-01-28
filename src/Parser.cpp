#include "Parser.hpp"
#include "IResult.hpp"
#include "Attribute.hpp"
#include "Data.hpp"
#include "TagInterpreter.hpp"
#include "XmlOpeningElement.hpp"
#include "XmlClosingElement.hpp"
#include "XmlElementContents.hpp"
#include "XmlEmptyElement.hpp"
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
  std::vector<TagInterpreter*> interpreters;
  interpreters.push_back(new XmlOpeningElement(result, &_validation));
  interpreters.push_back(new XmlElementContents(result, &_validation));
  interpreters.push_back(new XmlClosingElement(result, &_validation));
  interpreters.push_back(new XmlEmptyElement(result, &_validation));

  std::string line;
  while(std::getline(_fstream, line))
  {
    std::cout << "\n\n\n|" << line << "|" << std::endl;
    std::string str = trim(line);
    printf("trimmed line:%s<--\n", str.c_str());

    size_t start = 0;
    XmlLine* xmlLine = new XmlLine(str, start);

    do
    {
      for(size_t i=0; i<interpreters.size(); ++i)
      {
        if (interpreters[i]->interpret(xmlLine) == TagInterpreter::ERROR)
        {
          std::cout << "XML INVALID!" << std::endl;
          return false;
        }
        start = xmlLine->getCurrIndex();
        if (xmlLine->isAtEnd())
          break;
      }
    } while (start != str.length());
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
