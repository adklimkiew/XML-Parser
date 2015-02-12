#ifndef PARSER_HPP
#define PARSER_HPP

#include "XmlValidation.hpp"

#include <fstream>
#include <stack>
#include <string>
#include <vector>

class IResult;
class Attribute;
class XmlElementInterpreter;

class Parser
{
public:
  Parser(const std::string& filename);
  ~Parser();

  bool parse(IResult* result);

private:
  std::string trim(const std::string& str);
  void prepareInterpreters(std::vector<XmlElementInterpreter*>& interpreters, IResult* result);
  void deleteInterpreters(std::vector<XmlElementInterpreter*>& interpreters) const;

private:
  std::fstream _fstream;
  XmlValidation _validation;
};

#endif
