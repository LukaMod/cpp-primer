#ifndef EX_15_35_QUERYRESULT_H_
#define EX_15_35_QUERYRESULT_H_

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

    std::set<TextQuery::line_no>::iterator begin() const;
    std::set<TextQuery::line_no>::iterator end() const;
    std::shared_ptr<std::vector<std::string>> get_file() const;

  private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif