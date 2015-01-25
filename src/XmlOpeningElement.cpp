#include "XmlOpeningElement.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

bool XmlOpeningElement::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();
  std::cout << "interpret:" << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] == '<' && input[start+1] != '/')
  {
    size_t pos = input.find_first_of('>', start);
    std::cout << pos << std::endl;
    if (input[pos-1] == '/')
      return false;

    std::string tag;
    if (!extractAttributes(xmlLine, tag))
      return false;

    validation()->push(tag);

    xmlLine->setCurrIndex(pos+1);
    return true;
  }
  return false;
}
