#ifndef XML_VALIDATION_HPP
#define XML_VALIDATION_HPP

#include <stack>
#include <string>

class XmlValidation
{
public:
  void push(const std::string& element) { _stack.push(element); }
  const std::string& top() { return _stack.top(); }
  void pop() { _stack.pop(); }

  bool validate(const std::string& element) { return top() == element; }

private:
  std::stack<std::string> _stack;
};

#endif
