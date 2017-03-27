#ifndef EX_15_35_QUERY_BASE_H_
#define EX_15_35_QUERY_BASE_H_

#include "ex12_27_a.h"
#include "ex15_35_QueryResult.h"

class Query_base
{
    friend class Query;

  protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

  private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

#endif // !QUERY_BASE_H_
