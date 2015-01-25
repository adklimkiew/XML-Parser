#ifndef PARSER_HPP
#define PARSER_HPP

#include "XmlValidation.hpp"

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

private:
  std::fstream _fstream;
  XmlValidation _validation;
};

#endif
