#ifndef RESULT_HPP
#define RESULT_HPP

#include <string>
#include <vector>
#include <utility>
#include <iostream>

class Result
{
public:
  void add(const std::string& data, const std::string& descr)
  {
    _results.push_back(std::make_pair(data, descr));
  }

  void print() const
  {
    for (size_t i=0; i<_results.size(); ++i)
      std::cout << _results[i].second << ": " << _results[i].first << std::endl;
  }

private:
  std::vector<std::pair<std::string,std::string> > _results;
};

#endif
