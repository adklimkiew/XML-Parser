#ifndef XML_OPENING_ELEMENT_HPP
#define XML_OPENING_ELEMENT_HPP

#include "TagInterpreter.hpp"

class XmlOpeningElement : public TagInterpreter
{
public:
  XmlOpeningElement(IResult* result, XmlValidation* validation) : TagInterpreter(result, validation) {}
  TagInterpreter::RESULT interpret(XmlLine* xmlLine);
};

#endif
