#ifndef EX_15_35_BINARYQUERY_H_
#define EX_15_35_BINARYQUERY_H_

#include "ex15_35_Query_base.h"
#include "ex15_35_Query.h"

class BinaryQuery : public Query_base
{
  protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(l), opSym(s) {}

    virtual std::string rep() const
    {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }

    Query lhs;
    Query rhs;
    std::string opSym;
};

#endif // !BINARYQUERY_H_
