#ifndef XML_CLOSING_ELEMENT_HPP
#define XML_CLOSING_ELEMENT_HPP

#include "TagInterpreter.hpp"

class XmlClosingElement : public TagInterpreter
{
public:
  XmlClosingElement(IResult* result, XmlValidation* validation) : TagInterpreter(result, validation) {}
  bool interpret(XmlLine* xmlLine);
};

#endif
