#ifndef XML_OPENING_ELEMENT_HPP
#define XML_OPENING_ELEMENT_HPP

#include "XmlElementInterpreter.hpp"

class XmlOpeningElementInterpreter : public XmlElementInterpreter
{
public:
  XmlOpeningElementInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation), _pos(0) {}
  XmlElementInterpreter::RESULT interpret(XmlLine* xmlLine);

protected:
  bool elementMatches(XmlLine* xmlLine);

private:
  size_t _pos;
};

#endif
