#include "XmlOpeningElementInterpreter.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"

#include <string>
#include <iostream>

TagInterpreter::RESULT XmlOpeningElementInterpreter::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();
  std::cout << "Open interpret:" << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] != '<' || input[start+1] == '/')
    return TagInterpreter::IGNORED;

  size_t pos = input.find_first_of('>', start);
  if (pos == std::string::npos)
    return TagInterpreter::IGNORED;

  std::cout << pos << std::endl;
  if (input[pos-1] == '/')
    return TagInterpreter::IGNORED;

  std::string tag;
  if (!extractTagAndAttributes(xmlLine, tag))
    return TagInterpreter::ERROR;

  validation()->push(tag);

  xmlLine->setCurrIndex(pos+1);
  return TagInterpreter::SUCCESS;
}
