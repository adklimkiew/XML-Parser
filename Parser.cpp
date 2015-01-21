#include "Parser.hpp"
#include "Result.hpp"

#include <iostream>

Parser::Parser(const std::string& filename)
{
  _fstream.open(filename.c_str(), std::fstream::in); 
}

Parser::~Parser()
{
  _fstream.close(); 
}

bool Parser::parse(Result* result)
{
  std::string line;
  while(std::getline(_fstream, line))
  {
    std::cout << "|" << line << "|" << std::endl;
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
std::cout << "trim:" << start << " " << end << std::endl;
  if (end == std::string::npos)
    end = str.length() - 1;
  return str.substr(start, end-start);
}

bool Parser::evaluate(const std::string& str, size_t& start, Result* result)
{
  if (start == str.length())
    return true;
    
  std::string nextToken;
  switch(getNextToken(str, start, nextToken))
  {
    case OPENING_ELEMENT:
      _stack.push(nextToken);
      std::cout << "pushed " << _stack.top() << "("<< nextToken << ")" << std::endl;
      break;
    case CONTENTS:
      std::cout << "contents: " << nextToken << std::endl;
      result->add(new Data(nextToken, _stack.top()));  
      break;
    case CLOSING_ELEMENT:
      if(_stack.top() != nextToken){
        std::cout << "nextToken:" << nextToken << " top:" << _stack.top() << std::endl;
        return false;
      }
      _stack.pop();
      break;
    case EMPTY_ELEMENT:
      
      break;
  }
  return evaluate(str, start, result);
}

Parser::TOKEN Parser::getNextToken(const std::string& input, size_t& start, std::string& result)
{
  std::cout << input << "---" << input.length() << " " << start << std::endl;
  if (input[start] == '<' && input[start+1] != '/')
  {
    size_t pos = input.find_first_of('>', start);
    std::cout << pos << std::endl;
    if (input[pos-1] == '/')
    {
      result = input.substr(start+1, pos-2);
      start = pos+1;
      return EMPTY_ELEMENT;
    }
    result = input.substr(start+1, pos-start-1);
    std::cout << result << std::endl;
    start = pos+1;
    return OPENING_ELEMENT;
  }
  else if (input[start] != '<')
  {
    size_t pos = input.find_first_of('<', start);
    if (pos == std::string::npos) {
      result = input.substr(start, pos-start+1);
      start = input.length();
    }
    else {
      result = input.substr(start, pos-start);
      std::cout << pos << "[" << input[pos] << "]" << result << std::endl;
      start = pos;
    }
    return CONTENTS;   
  }
  else
  {
    size_t pos = input.find_first_of('>', start+2);
    result = input.substr(start+2, pos-1-start-1);
    if (pos == input.length()-1)
      start = input.length();
    else
      start = pos+1;
    std::cout << result << std::endl;
    return CLOSING_ELEMENT;
  }
}
