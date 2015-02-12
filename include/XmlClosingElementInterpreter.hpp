#ifndef XML_CLOSING_ELEMENT_HPP
#define XML_CLOSING_ELEMENT_HPP

#include "XmlElementInterpreter.hpp"

class XmlClosingElementInterpreter : public XmlElementInterpreter
{
public:
  XmlClosingElementInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation) {}
  RESULT interpret(XmlLine* xmlLine);

protected:
  bool elementMatches(XmlLine* xmlLine);
};

#endif
