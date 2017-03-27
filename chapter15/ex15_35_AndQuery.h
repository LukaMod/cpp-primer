#ifndef EX_15_35_ANDQUERY_H_
#define EX_15_35_ANDQUERY_H_

#include "ex15_35_BinaryQuery.h"

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);

    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}

    virtual QueryResult eval(const TextQuery &) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif // !ANDQUERY_H_
