#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_

#include <memory>
#include <string>
#include <vector>
#include <set>

#include "ex12_27_a.h"

class QueryResult
{
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  QueryResult(const std::string &, std::shared_ptr<std::set<TextQuery::line_no>>, std::shared_ptr<std::vector<std::string>>);

private:
  std::string sought;
  std::shared_ptr<std::set<TextQuery::line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};

#endif