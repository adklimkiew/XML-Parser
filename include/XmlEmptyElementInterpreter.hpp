#ifndef XML_EMPTY_ELEMENT_HPP
#define XML_EMPTY_ELEMENT_HPP

#include "XmlElementInterpreter.hpp"

class XmlEmptyElementInterpreter : public XmlElementInterpreter
{
public:
  XmlEmptyElementInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation) {}

protected:
  bool elementMatches(XmlLine* xmlLine);
  bool extractData(const XmlLine* xmlLine, Data* data) const;
  bool postValidate(Data*) { return true; }
  void update(XmlLine* xmlLine);

private:
  size_t _pos;
};

#endif
