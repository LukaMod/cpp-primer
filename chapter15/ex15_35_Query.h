#ifndef EX_15_35_QUERY_H_
#define EX_15_35_QUERY_H_

#include <string>
#include <memory>

#include "ex15_35_Query_base.h"
#include "ex15_35_WordQuery.h"

class Query
{
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);

  public:
    Query(const std::string &s) : q(new WordQuery(s)) {}

    QueryResult eval(const TextQuery &t) const { return q->eval(t); }
    std::string rep() const { return q->rep(); }

  private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}

    std::shared_ptr<Query_base> q;
};

#endif // !QUERY_H_
