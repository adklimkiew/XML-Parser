#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <stack>
#include <string>
#include <vector>

class IResult;
class Attribute;

class Parser
{
public:
  Parser(const std::string& filename);
  ~Parser();

  bool parse(IResult* result);

private:
  enum TOKEN {OPENING_ELEMENT, CLOSING_ELEMENT, CONTENTS, EMPTY_ELEMENT};
  
  bool evaluate(const std::string& str, size_t& start, IResult* result);
  std::string trim(const std::string& str);

  TOKEN getNextToken(const std::string& input, size_t& start, std::string& result);

  bool extractAttributes(std::string const& input, std::string& element, std::vector<Attribute*>& results); 
  bool extractAttribute(std::string const& input, size_t& pos, std::vector<Attribute*>& results);
private:
  std::fstream _fstream;
  std::stack<std::string> _stack;
};

#endif
