#ifndef EX_12_32_TEXTQUERY_H_
#define EX_12_32_TEXTQUERY_H_

#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>

#include "ex12_32_StrBlob.h"

class QueryResult;

class TextQuery
{
  public:
    using line_no = std::vector<std::string>::size_type;

    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

  private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif