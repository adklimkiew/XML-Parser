#include "VResult.hpp"

void VResult::print() const
{
  for (size_t i=0; i<_results.size(); ++i)
    _results[i]->print();
}

std::vector<Data*> VResult::find(const std::string& tag)
{
  std::vector<Data*> foundData;
  for (size_t i=0; i<_results.size(); ++i)
    if (_results[i]->getTag() == tag)
      foundData.push_back(_results[i]);

  return foundData;
}
