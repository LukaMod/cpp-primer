#include "ex12_27_b.h"

#include <memory>
#include <string>
#include <iostream>

using namespace std;

QueryResult::QueryResult(const string &s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << (qr.lines->size() > 1 ? " times" : "time") << std::endl;
    for (const auto &num : *qr.lines)
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << std::endl;
    return os;
}
