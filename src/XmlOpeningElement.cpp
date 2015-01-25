#include "XmlOpeningElement.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

TagInterpreter::RESULT XmlOpeningElement::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();
  std::cout << "interpret:" << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] == '<' && input[start+1] != '/')
  {
    size_t pos = input.find_first_of('>', start);
    std::cout << pos << std::endl;
    if (input[pos-1] == '/')
      return TagInterpreter::IGNORED;

    std::string tag;
    if (!extractAttributes(xmlLine, tag))
      return TagInterpreter::ERROR;

    validation()->push(tag);

    xmlLine->setCurrIndex(pos+1);
    return TagInterpreter::SUCCESS;
  }
  return TagInterpreter::IGNORED;
}
