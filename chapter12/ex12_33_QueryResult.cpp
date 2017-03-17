#include "ex12_33_QueryResult.h"

#include <memory>
#include <string>
#include <iostream>

using namespace std;

QueryResult::QueryResult(const string &s, shared_ptr<set<TextQuery::line_no>> p, StrBlob f) : sought(s), lines(p), file(f) {}

std::set<TextQuery::line_no>::iterator QueryResult::begin()
{
    return lines->begin();
}

std::set<TextQuery::line_no>::iterator QueryResult::end()
{
    return lines->end();
}

std::shared_ptr<StrBlob> QueryResult::get_file() const
{
    return make_shared<StrBlob>(file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << (qr.lines->size() > 1 ? " times" : "time") << std::endl;
    for (const auto &num : *qr.lines)
        os << "\t(line " << num + 1 << ") "
           << qr.file.data->at(num) << std::endl;
    return os;
}
