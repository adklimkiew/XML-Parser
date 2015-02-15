#include "XmlOpeningElementInterpreter.hpp"
#include "XmlValidation.hpp"
#include "IResult.hpp"
#include "XmlLine.hpp"
#include "Data.hpp"

#include <string>
#include <iostream>

XmlElementInterpreter::RESULT XmlOpeningElementInterpreter::interpret(XmlLine* xmlLine)
{
  return interpret_template_method(xmlLine);
}

void XmlOpeningElementInterpreter::update(XmlLine* xmlLine)
{
  xmlLine->setCurrIndex(_pos+1);
}

bool XmlOpeningElementInterpreter::extractData(const XmlLine* xmlLine, Data* data) const
{
  std::string tag;
  std::vector<Attribute*> attributes;
  if (!extractTagAndAttributes(xmlLine, tag, attributes))
    return false;

  data->setTag(tag);
  data->setAttributes(attributes);

  return true;
}

bool XmlOpeningElementInterpreter::postValidate(Data* data)
{
  validation()->push(data->getTag());
  
  if (!validation()->validateRootElement())
  {
    std::cout << "XmlOpeningElementInterpreter::more than one root element!" << std::endl;
    return false;
  }

  return true;
}

bool XmlOpeningElementInterpreter::elementMatches(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();
  std::cout << "Open interpret:" << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] != '<' || input[start+1] == '/')
    return false;

  _pos = input.find_first_of('>', start);
  if (_pos == std::string::npos)
    return false;

  std::cout << _pos << std::endl;
  if (input[_pos-1] == '/')
    return false;

  return true;
}
