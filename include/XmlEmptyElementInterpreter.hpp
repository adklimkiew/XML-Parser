#ifndef XML_EMPTY_ELEMENT_HPP
#define XML_EMPTY_ELEMENT_HPP

#include "TagInterpreter.hpp"

class XmlEmptyElementInterpreter : public TagInterpreter
{
public:
  XmlEmptyElementInterpreter(IResult* result, XmlValidation* validation) : TagInterpreter(result, validation) {}
  RESULT interpret(XmlLine* xmlLine);
};

#endif
