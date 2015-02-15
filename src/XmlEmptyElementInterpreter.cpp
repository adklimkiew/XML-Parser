#include "XmlEmptyElementInterpreter.hpp"
#include "XmlValidation.hpp"
#include "IResult.hpp"
#include "XmlLine.hpp"
#include "Data.hpp"

#include <string>
#include <iostream>

bool XmlEmptyElementInterpreter::elementMatches(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  std::cout << "Empty elem interpret:" << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] != '<' || input[start+1] == '/')
    return false;

  _pos = input.find_first_of('>', start);
  std::cout << _pos << std::endl;
  if (input[_pos-1] != '/')
    return false;

  return true;
}

bool XmlEmptyElementInterpreter::extractData(const XmlLine* xmlLine, Data* data) const
{
  std::string tag;
  std::vector<Attribute*> attributes;
  if (!extractTagAndAttributes(xmlLine, tag, attributes))
    return false;

  data->setTag(tag);
  data->setAttributes(attributes);

  return true;
}

void XmlEmptyElementInterpreter::update(XmlLine* xmlLine)
{
  xmlLine->setCurrIndex(_pos+1);
}
