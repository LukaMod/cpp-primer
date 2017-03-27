#ifndef EX_15_35_WORDQUERY_H_
#define EX_15_35_WORDQUERY_H_

#include "ex15_35_Query_base.h"

class WordQuery : public Query_base
{
    friend class Query;

    WordQuery(const std::string &s) : query_word(s) {}

    virtual QueryResult eval(const TextQuery &t) const override
    {
        return t.query(query_word);
    }
    virtual std::string rep() const { return query_word; }

    std::string query_word;
};

#endif // !WORDQUERY_H_
