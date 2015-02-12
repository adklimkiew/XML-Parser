#include "XmlEmptyElementInterpreter.hpp"
#include "XmlValidation.hpp"
#include "IResult.hpp"
#include "XmlLine.hpp"
#include "Data.hpp"

#include <string>
#include <iostream>

XmlElementInterpreter::RESULT XmlEmptyElementInterpreter::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();
  std::cout << "Empty elem interpret:" << input << "---" << input.length() << " " << start << std::endl;

  if (input[start] == '<' && input[start+1] != '/')
  {
    size_t pos = input.find_first_of('>', start);
    std::cout << pos << std::endl;
    if (input[pos-1] != '/') // this is not empty element...
      return XmlElementInterpreter::IGNORED;

    std::string tag;
    std::vector<Attribute*> attributes;
    if(!extractTagAndAttributes(xmlLine, tag, attributes))
      return XmlElementInterpreter::ERROR;

    result()->add(new Data(tag, attributes));

    std::cout << "Empty elem interpret extracted tag: " << tag << std::endl;

    xmlLine->setCurrIndex(pos+1);
    return XmlElementInterpreter::SUCCESS;
  }
  return XmlElementInterpreter::IGNORED;
}
