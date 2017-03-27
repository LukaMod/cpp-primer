#include "ex15_35_QueryResult.h"

#include <memory>
#include <string>
#include <iostream>

using namespace std;

QueryResult::QueryResult(const string &s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}

std::set<TextQuery::line_no>::iterator QueryResult::begin() const
{
    return lines->begin();
}

std::set<TextQuery::line_no>::iterator QueryResult::end() const
{
    return lines->end();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file() const
{
    return file;
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << (qr.lines->size() > 1 ? " times" : "time") << std::endl;
    for (const auto &num : *qr.lines)
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << std::endl;
    return os;
}
