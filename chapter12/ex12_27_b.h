#ifndef EX_12_27_B_H
#define EX_12_27_B_H

#include <memory>
#include <string>
#include <vector>
#include <set>

#include "ex12_27_a.h"

using std::shared_ptr;
using std::string;
using std::vector;
using std::set;

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

  public:
    QueryResult(const string &, shared_ptr<set<TextQuery::line_no>>, shared_ptr<vector<string>>);

  private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

#endif