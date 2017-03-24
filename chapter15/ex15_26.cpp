#include "ex15_26_Bulk_quote.h"

int main()
{
    Bulk_quote bq1;
    Bulk_quote bq2("xyx", 7.14, 93, 0.14);
    bq2 = std::move(bq2);
    return 0;
}