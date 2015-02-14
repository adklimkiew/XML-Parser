#ifndef XML_ELEMENT_INTERPRETER_HPP
#define XML_ELEMENT_INTERPRETER_HPP

#include <vector>
#include <string>

class IResult;
class XmlValidation;
class XmlLine;
class Attribute;

class XmlElementInterpreter
{
public:
  XmlElementInterpreter(IResult* result, XmlValidation* validation) :
    _result(result), _validation(validation) {}

  virtual ~XmlElementInterpreter() {}

  enum RESULT {SUCCESS, IGNORED, ERROR};

  virtual RESULT interpret(XmlLine* xmlLine) = 0;

protected:
  virtual bool elementMatches(XmlLine* xmlLine) = 0;

  IResult* result() { return _result; }
  XmlValidation* validation() { return _validation; }

  bool extractTagAndAttributes(const XmlLine* xmlLine, std::string& tag, std::vector<Attribute*>& attributes);

private:
  bool extractAttributes(const std::string& input, size_t& pos, std::vector<Attribute*>& attributes);
  bool extractAttribute(std::string const& input, size_t& pos, std::vector<Attribute*>& attributes);

  IResult* _result;
  XmlValidation* _validation;
};

#endif
