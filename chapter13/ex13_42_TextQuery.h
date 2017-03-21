#ifndef EX_13_42_TEXTQUERY_H_
#define EX_13_42_TEXTQUERY_H_

#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>

#include "ex13_40.h"

class QueryResult;

class TextQuery
{
  public:
    using line_no = size_t;

    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

  private:
    std::shared_ptr<StrVec> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif