#ifndef XML_CLOSING_ELEMENT_HPP
#define XML_CLOSING_ELEMENT_HPP

#include "TagInterpreter.hpp"

class XmlClosingElementInterpreter : public TagInterpreter
{
public:
  XmlClosingElementInterpreter(IResult* result, XmlValidation* validation) : TagInterpreter(result, validation) {}
  RESULT interpret(XmlLine* xmlLine);
};

#endif
