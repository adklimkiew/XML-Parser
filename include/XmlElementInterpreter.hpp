#ifndef XML_ELEMENT_INTERPRETER_HPP
#define XML_ELEMENT_INTERPRETER_HPP

#include "Data.hpp"
#include "IResult.hpp"

#include <vector>
#include <string>

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

  RESULT interpret(XmlLine* xmlLine);

protected:
  virtual bool elementMatches(XmlLine* xmlLine) = 0;
  virtual bool preValidate() { return true; }
  virtual Data* prepareData() const { return new Data(); }
  virtual bool extractData(const XmlLine* xmlLine, Data* data) const = 0;
  virtual bool postValidate(Data* data) = 0;
  virtual void store(Data* data) { result()->add(data); }
  virtual void update(XmlLine*) {}
  virtual void cleanup() {}

  IResult* result() { return _result; }
  XmlValidation* validation() { return _validation; }

  bool extractTagAndAttributes(const XmlLine* xmlLine, std::string& tag, std::vector<Attribute*>& attributes) const;

private:
  bool extractAttributes(const std::string& input, size_t& pos, std::vector<Attribute*>& attributes) const;
  bool extractAttribute(const std::string& input, size_t& pos, std::vector<Attribute*>& attributes) const;

  IResult* _result;
  XmlValidation* _validation;
};

#endif
