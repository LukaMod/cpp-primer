#ifndef EX_15_35_ORQUERY_H_
#define EX_15_35_ORQUERY_H_

#include "ex15_35_BinaryQuery.h"

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);

    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}

    virtual QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif // !ORQUERY_H_
