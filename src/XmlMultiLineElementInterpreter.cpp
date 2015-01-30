#include "XmlMultiLineElementInterpreter.hpp"
#include "XmlValidation.hpp"
#include "XmlLine.hpp"
#include "MultiLineElement.hpp"
#include "IResult.hpp"
#include "Data.hpp"

#include <string>
#include <iostream>

TagInterpreter::RESULT XmlMultiLineElementInterpreter::interpret(XmlLine* xmlLine)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();
  std::cout << "Multi-line interpret:" << input << "---" << input.length() << " " << start << std::endl;

if (_multiLineElement == NULL)
{
  if (input[start] != '<' || input[start+1] == '/')
    return TagInterpreter::IGNORED;

  size_t pos = input.find_first_of('>', start);
  if (pos != std::string::npos)
    return TagInterpreter::IGNORED;

  _multiLineElement = new MultiLineElement();

// EXTRACT TAG -> CODE DUPLICATION!!!
  pos = input.find_first_of(" >", start);
  _multiLineElement->_tag = input.substr(start+1, pos-start-1);
  std::cout << "tag extracted: " << _multiLineElement->_tag << std::endl;
/////////////////////////////////////

  std::vector<Attribute*> attributes;
  if (!extractAttributes(input, pos, attributes))
    return TagInterpreter::ERROR;

  _multiLineElement->add(attributes);

  xmlLine->setCurrIndex(input.length());
  return TagInterpreter::SUCCESS;
}
else
{
  size_t pos = input.find_first_of('>', start);
  if (pos == std::string::npos)
  {  
// EXTRACT ATTRIBUTES -> CODE DUPLICATION see above!!!
    pos = 0; // reset...
    std::vector<Attribute*> attributes;
    if (!extractAttributes(input, pos, attributes))
      return TagInterpreter::ERROR;

    xmlLine->setCurrIndex(input.length());
    _multiLineElement->add(attributes);
   return TagInterpreter::SUCCESS;
  }

  result()->add(new Data(_multiLineElement->_tag, _multiLineElement->attributes()));

  if (input[pos-1] == '/') // empty element
  {
    xmlLine->setCurrIndex(input.length());

    delete _multiLineElement;
   _multiLineElement = NULL;
    return TagInterpreter::SUCCESS;
  }
  else // opening element
  {
    validation()->push(_multiLineElement->_tag);

    delete _multiLineElement;
    _multiLineElement = NULL;

    xmlLine->setCurrIndex(pos+1);
    return TagInterpreter::SUCCESS;
  }
}

return TagInterpreter::IGNORED;
}
