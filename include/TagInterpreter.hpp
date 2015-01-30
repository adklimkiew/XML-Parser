#ifndef TAG_INTERPRETER_HPP
#define TAG_INTERPRETER_HPP

#include <vector>
#include <string>

class IResult;
class XmlValidation;
class XmlLine;
class Attribute;

class TagInterpreter
{
public:
  TagInterpreter(IResult* result, XmlValidation* validation) :
    _result(result), _validation(validation) {}

  virtual ~TagInterpreter() {}

  enum RESULT {SUCCESS, IGNORED, ERROR};

  virtual RESULT interpret(XmlLine* xmlLine) = 0;

protected:
  IResult* result() { return _result; }
  XmlValidation* validation() { return _validation; }

  bool extractTagAndAttributes(const XmlLine* xmlLine, std::string& tag);
  bool extractAttributes(const std::string& input, size_t& pos, std::vector<Attribute*>& results);
  bool extractAttribute(std::string const& input, size_t& pos, std::vector<Attribute*>& results);

private:
  IResult* _result;
  XmlValidation* _validation;
};

#endif
