#include "Parser.hpp"
#include "Result.hpp"

#include <iostream>

Parser::Parser(const std::string& filename)
{
  _fstream.open(filename, std::fstream::in); 
}

Parser::~Parser()
{
  _fstream.close(); 
}

bool Parser::parse(Result* result)
{
  std::string line;
  while( std::getline(_fstream, line))
  {
    std::cout << line << std::endl;
    std::string str = trim(line);
    if(!evaluate(str, result))
    {
      std::cout << "XML INVALID!" << std::endl;
      return false;
    }
  } 
}

std::string Parser::trim(const std::string& str)
{
  size_t start = str.find_first_not_of(' ');
  size_t end = str.find_last_not_of(' ');
  return str.substr(start, end-start+1);
}

bool Parser::evaluate(std::string& str, Result* result)
{
  if (str.empty())
    return true;
    
  std::string res;
  switch(getNextToken(str, res))
  {
    case OPENING_ELEMENT:
      _stack.push(res);
      std::cout << "pushed " << _stack.top() << "("<< res << ")" << std::endl;
      break;
    case CONTENTS:
      result->add(res,_stack.top());  
      break;
    case CLOSING_ELEMENT:
      std::string& top = _stack.top();
      if(top != res){
        std::cout << "res:" << res << " top:" << top << std::endl;
        return false;
      }
      _stack.pop();
      break;
  }
  return evaluate(str, result);
}

Parser::TOKEN Parser::getNextToken(std::string& input, std::string& result)
{
  if (input[0] == '<' && input[1] != '/')
  {
    size_t pos = input.find_first_of('>');
    std::cout << pos << std::endl;
    result = input.substr(1, pos-1);
    std::cout << result << std::endl;
    if (pos+1 == input.length())
      input = "";
    else
      input = input.substr(pos+1, input.length()-pos);
    return OPENING_ELEMENT;
  }
  else if (input[0] != '<')
  {
    size_t pos = input.find_first_of('<');
    if (pos == std::string::npos) {
      result = input;
      input = "";
    }
    else {
      result = input.substr(0, pos);
      std::cout << result << std::endl;
      input = input.substr(pos, input.length()-pos);
    }
    return CONTENTS;   
  }
  else
  {
    size_t pos = input.find_first_of('>', 2);
    result = input.substr(2, pos-2);
    input = input.substr(pos+1, input.length()-pos);
    std::cout << result << std::endl;
    return CLOSING_ELEMENT;
  }
}
