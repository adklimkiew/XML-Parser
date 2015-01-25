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
  std::string line;
  while(std::getline(_fstream, line))
  {
    std::cout << "\n\n\n|" << line << "|" << std::endl;
    std::string str = trim(line);
    printf("trimmed line:%s<--\n", str.c_str());
    size_t start = 0;
    if(!evaluate(str, start, result))
    {
      std::cout << "XML INVALID!" << std::endl;
      return false;
    }
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

bool Parser::evaluate(const std::string& str, size_t& start, IResult* result)
{
  if (start == str.length())
    return true;
    
  std::string nextToken;
  switch(getNextToken(str, start, nextToken))
  {
    case OPENING_ELEMENT:
    {
      TagInterpreter* ti = new XmlOpeningElement(result, &_validation);
      std::cout << "OPENING: nextToken:" << nextToken << " start: " << start << "\'" << nextToken[start] << "\'" << std::endl;
      XmlLine* line = new XmlLine(nextToken, start);
      if(!ti->interpret(line)) {
        std::cout << "nextToken:" << nextToken << " onTop:" << _validation.top() << std::endl;
        // memory leak...!
        return false;        
      }
      start = line->getCurrIndex();
      delete line;
      delete ti;

      break;
    }
    case CONTENTS:
    {
      TagInterpreter* ti = new XmlElementContents(result, &_validation);
      std::cout << "CONTENTS: nextToken:" << nextToken << " start: " << start << "\'" << nextToken[start] << "\'" << std::endl;
      XmlLine* line = new XmlLine(nextToken, start);
      if(!ti->interpret(line)) {
        std::cout << "nextToken:" << nextToken << " onTop:" << _validation.top() << std::endl;
        // memory leak...!
        return false;        
      }
      start = line->getCurrIndex();
      delete line;
      delete ti;

      break;
    }
    case CLOSING_ELEMENT:
    {    
      TagInterpreter* ti = new XmlClosingElement(result, &_validation);
      std::cout << "CLOSING: nextToken:" << nextToken << " start: " << start << "\'" << nextToken[start] << "\'" << std::endl;
      XmlLine* line = new XmlLine(nextToken, start);
      if(!ti->interpret(line)) {
        std::cout << "nextToken:" << nextToken << " onTop:" << _validation.top() << std::endl;
        // memory leak...!
        return false;        
      }
      start = line->getCurrIndex();
      delete line;
      delete ti;

      break;
    }
    case EMPTY_ELEMENT:
      std::cout << "EMPTY: " << nextToken << std::endl;
      TagInterpreter* ti = new XmlEmptyElement(result, &_validation);
      XmlLine* line = new XmlLine(nextToken, start);
      if(!ti->interpret(line)) {
        std::cout << "nextToken:" << nextToken << " onTop:" << _validation.top() << std::endl;
        // memory leak...!
        return false;        
      }
      start = line->getCurrIndex();
      delete line;
      delete ti;

      break;
  }
  return evaluate(str, start, result);
}

Parser::TOKEN Parser::getNextToken(const std::string& input, size_t& start, std::string& result)
{
  std::cout << input << "---" << input.length() << " " << start << std::endl;
  size_t pos = input.find_first_of('>', start);
  if (input[start] == '<' && input[start+1] != '/' && input[pos-1] != '/')
  {
    result = input; // tmp hack
    return OPENING_ELEMENT;
  }
  else if (input[start] == '<' && input[start+1] != '/' && input[pos-1] == '/')
  {
    result = input; // tmp hack
    return EMPTY_ELEMENT;
  }
  else if (input[start] != '<')
  {
    result = input; // tmp hack
    return CONTENTS;
  }
  else
  {
    result = input; // tmp hack
    return CLOSING_ELEMENT;
  }
}
