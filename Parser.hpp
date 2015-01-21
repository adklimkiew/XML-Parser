#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <stack>
#include <string>

class Result;

class Parser
{
public:
  Parser(const std::string& filename);
  ~Parser();

  bool parse(Result* result);

private:
  enum TOKEN {OPENING_ELEMENT, CLOSING_ELEMENT, CONTENTS};
  
  bool evaluate(const std::string& str, size_t& start, Result* result);
  std::string trim(const std::string& str);

  TOKEN getNextToken(const std::string& input, size_t& start, std::string& result);
  
private:
  std::fstream _fstream;
  std::stack<std::string> _stack;
};

#endif