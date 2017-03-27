#ifndef EX_15_35_NOTQUERY_H_
#define EX_15_35_NOTQUERY_H_

#include "ex15_35_Query_base.h"
#include "ex15_35_Query.h"

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);

    NotQuery(const Query &q) : query(q) {}

    virtual std::string rep() const { return "~(" + query.rep() + ")"; }
    virtual QueryResult eval(const TextQuery &) const;

    Query query;
};

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

#endif // !NOTQUERY_H_
