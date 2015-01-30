#ifndef VRESULT_HPP
#define VRESULT_HPP

#include "IResult.hpp"
#include "Data.hpp"

#include <vector>

class VResult : public IResult
{
public:
  ~VResult() {}

  void add(Data* data) { _results.push_back(data); }
  
  Data* getLast() {
    if (_results.size() > 0)
      return _results[_results.size()-1];
    return 0;  
  }
  void print() const;

private:
  std::vector<Data*> _results;
};

#endif
