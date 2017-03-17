#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_

#include <memory>
#include <string>
#include <vector>
#include <set>

#include "ex12_32_TextQuery.h"
#include "ex12_32_StrBlob.h"

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

  public:
    QueryResult(const std::string &, std::shared_ptr<std::set<TextQuery::line_no>>, StrBlob);

  private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    StrBlob file;
};

#endif