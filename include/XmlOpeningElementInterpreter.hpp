#ifndef XML_OPENING_ELEMENT_HPP
#define XML_OPENING_ELEMENT_HPP

#include "TagInterpreter.hpp"

class XmlOpeningElementInterpreter : public TagInterpreter
{
public:
  XmlOpeningElementInterpreter(IResult* result, XmlValidation* validation) : TagInterpreter(result, validation) {}
  TagInterpreter::RESULT interpret(XmlLine* xmlLine);
};

#endif
