#ifndef XML_ELEMENT_CONTENTS_HPP
#define XML_ELEMENT_CONTENTS_HPP

#include "XmlElementInterpreter.hpp"

class XmlElementContentsInterpreter : public XmlElementInterpreter
{
public:
  XmlElementContentsInterpreter(IResult* result, XmlValidation* validation) : XmlElementInterpreter(result, validation) {}

protected:
  bool elementMatches(XmlLine* xmlLine);
  bool preValidate();
  Data* prepareData() const;
  bool extractData(const XmlLine* xmlLine, Data* data) const;
  bool postValidate(Data*) { return true; }
  void store(Data*) {}
  void update(XmlLine* xmlLine);

private:
  size_t _pos;
};

#endif
