#ifndef RESULT_HPP
#define RESULT_HPP

#include "Data.hpp"

#include <vector>

class Result
{
public:
  void add(Data* data)
  {
    _results.push_back(data);
  }

  void print() const
  {
    for (size_t i=0; i<_results.size(); ++i)
      _results[i]->print();
  }

private:
  std::vector<Data*> _results;
};

#endif
