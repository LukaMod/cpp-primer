#ifndef EX_13_42_QUERYRESULT_H_
#define EX_13_42_QUERYRESULT_H_

#include <memory>
#include <string>
#include <set>

#include "ex13_42_TextQuery.h"
#include "ex13_40.h"

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

  public:
    QueryResult(const std::string &, std::shared_ptr<std::set<TextQuery::line_no>>, std::shared_ptr<StrVec>);

  private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<StrVec> file;
};

#endif