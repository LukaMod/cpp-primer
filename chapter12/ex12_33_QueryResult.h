#ifndef EX_12_33_QUERYRESULT_H_
#define EX_12_33_QUERYRESULT_H_

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
    std::set<TextQuery::line_no>::iterator begin();
    std::set<TextQuery::line_no>::iterator end();
    std::shared_ptr<StrBlob> get_file() const;

  private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    StrBlob file;
};

#endif