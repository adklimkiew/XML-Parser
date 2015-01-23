#include "Result.hpp"

void Result::print() const
{
  for (size_t i=0; i<_results.size(); ++i)
    _results[i]->print();
}
