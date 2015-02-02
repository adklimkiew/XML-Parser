#ifndef XML_VALIDATION_HPP
#define XML_VALIDATION_HPP

#include <stack>
#include <string>

class XmlValidation
{
public:
  XmlValidation() : _rootElementFound(false), _singleRootElement(true), _contentsAllowed(false) {}

  void push(const std::string& element) {
    if (_stack.empty() && _rootElementFound == false)
      _rootElementFound = true;
    else if (_stack.empty() && _rootElementFound)
      _singleRootElement = false;      
    _stack.push(element);
    _contentsAllowed = true;
  }
  const std::string& top() const { return _stack.top(); }
  void pop() { _stack.pop(); _contentsAllowed = false; }

  bool validate(const std::string& element) const { return top() == element; }
  bool validateRootElement() const { return _singleRootElement; }
  bool validateContentsProperlyNested() const { return _contentsAllowed; }

private:
  std::stack<std::string> _stack;
  bool _rootElementFound;
  bool _singleRootElement;
  bool _contentsAllowed;
};

#endif
