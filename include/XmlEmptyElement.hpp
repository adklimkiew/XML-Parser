#ifndef XML_EMPTY_ELEMENT_HPP
#define XML_EMPTY_ELEMENT_HPP

#include "TagInterpreter.hpp"

class XmlEmptyElement : public TagInterpreter
{
public:
  XmlEmptyElement(IResult* result, XmlValidation* validation) : TagInterpreter(result, validation) {}
  bool interpret(XmlLine* xmlLine);
};

#endif
