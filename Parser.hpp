#include <fstream>
#include <stack>

class Parser
{
public:
  Parser(const std::string& filename);
  ~Parser();

  bool parse();

private:
  enum TOKEN {OPENING_ELEMENT, CLOSING_ELEMENT, CONTENTS};
  
  bool evaluate(std::string& str);

  TOKEN getNextToken(std::string& input, std::string& result);
  
private:
  std::string _filename;
  std::fstream _fstream;
  std::stack<std::string> _stack;
};
