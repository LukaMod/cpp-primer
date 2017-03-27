#include "ex15_35_NotQuery.h"

using namespace std;

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (auto i = 0; i != sz; ++i)
    {
        if (beg == end || *beg != i)
            ret_lines->insert(i);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}
