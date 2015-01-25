#include "XmlEmptyElement.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

bool XmlEmptyElement::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();
  std::cout << "interpret:" << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] == '<' && input[start+1] != '/')
  {
    size_t pos = input.find_first_of('>', start);
    std::cout << pos << std::endl;
    if (input[pos-1] != '/') // this is not empty element...
      return false;

    std::string tag; // <- not needed in fact... - tbd
    if(!extractAttributes(xmlLine, tag))
      return false;

    std::cout << "interpret extracted tag: " << tag << std::endl;

    xmlLine->setCurrIndex(pos+1);
    return true;
  }
  return false;
}
