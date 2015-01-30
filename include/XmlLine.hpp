#ifndef XML_LINE_HPP
#define XML_LINE_HPP

#include <string>

class XmlLine
{
public:
  XmlLine(const std::string& input, size_t currIndex = 0/*tmp*/) : _input(input), _currIndex(currIndex) {}

  const std::string& input() const { return _input; }
  bool isAtEnd() const { return _currIndex == _input.length(); }

  size_t getCurrIndex() const { return _currIndex; }
  void setCurrIndex(size_t index) { _currIndex = index; }

private:
  const std::string& _input;
  size_t _currIndex;
};

#endif
