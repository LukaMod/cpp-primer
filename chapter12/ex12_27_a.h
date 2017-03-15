#ifndef EX_12_27_A_H_
#define EX_12_27_A_H_

#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>

#include "ex12_27_b.h"

using std::vector;
using std::map;
using std::set;
using std::string;
using std::shared_ptr;
using std::ifstream;

class TextQuery
{
  public:
    using line_no = vector<string>::size_type;

    TextQuery(ifstream &);
    QueryResult query(const string &) const;

  private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

#endif