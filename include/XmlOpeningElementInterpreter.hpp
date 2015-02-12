#ifndef XML_OPENING_ELEMENT_HPP
#define XML_OPENING_ELEMENT_HPP

#include "XmlElementInterpreter.hpp"

class XmlOpeningElementInterpreter : public XmlElementInterpreter
{
public:
  XmlOpeningElementInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation) {}
  XmlElementInterpreter::RESULT interpret(XmlLine* xmlLine);
};

#endif
