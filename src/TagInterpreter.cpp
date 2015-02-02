#include "TagInterpreter.hpp"
#include "XmlLine.hpp"
#include "Attribute.hpp"
#include "XmlValidation.hpp"

#include <iostream>

bool TagInterpreter::extractTagAndAttributes(const XmlLine* xmlLine, std::string& tag, std::vector<Attribute*>& attributes)
{
  const std::string& input = xmlLine->input();
  size_t start = xmlLine->getCurrIndex();

  size_t pos = input.find_first_of(" >", start);
  std::cout << "extractTagAndAttributes: copy range" << start+1 << ", " << pos-start-1<< std::endl;
  tag = input.substr(start+1, pos-start-1);

  std::cout << "extractTagAndAttributes: tag to push:" << tag << "| pos:" << pos << " start:" << start << std::endl;

  if(!extractAttributes(input, pos, attributes))
    return false;

  std::cout << "extractAttributes: attributes.size:" << attributes.size() << std::endl;

  return true;
}

bool TagInterpreter::extractAttributes(const std::string& input, size_t& pos, std::vector<Attribute*>& attributes)
{
  while (pos != std::string::npos)
  {
    pos = input.find_first_of('=', pos);
    if (pos == std::string::npos)
      break;

    if (!extractAttribute(input, pos, attributes))
      return false;
  }
  return true;
}

bool TagInterpreter::extractAttribute(const std::string& input, size_t& pos, std::vector<Attribute*>& attributes)
{
  size_t index = pos-1;
  std::cout << pos << " " << input[pos] << std::endl;
  while(input[index] == ' ')
    --index;
  size_t end = index;

  while(input[index] != ' ' && index > 0)
    --index;
  std::string attrName = index == 0 ? input.substr(0, end-index+1) : input.substr(index+1, end-index);

  std::cout << "|" << attrName << "| " << index << ", " << end << std::endl;

  index = pos+1;
  while(input[index] == ' ')
    ++index;

  if (input[index] != '\"')
    return false;
  
  end = index+1;
  while(input[end] != '\"')
    ++end;

  std::string attrValue = input.substr(index+1, end-index-1);

  std::cout << attrValue << " " << index << ", " << end << std::endl;

  pos = end+1;

  attributes.push_back(new Attribute(attrName, attrValue));

  return true;
}
