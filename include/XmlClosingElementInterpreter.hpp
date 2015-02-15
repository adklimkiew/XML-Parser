#ifndef XML_CLOSING_ELEMENT_HPP
#define XML_CLOSING_ELEMENT_HPP

#include "XmlElementInterpreter.hpp"

class XmlClosingElementInterpreter : public XmlElementInterpreter
{
public:
  XmlClosingElementInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation), _pos(0) {}
  RESULT interpret(XmlLine* xmlLine);

protected:
  bool elementMatches(XmlLine* xmlLine);
  bool extractData(const XmlLine* xmlLine, Data* data) const;
  bool postValidate(Data* data);
  void update(XmlLine* xmlLine);
  void store(Data* data);

private:
  size_t _pos;
};

#endif
