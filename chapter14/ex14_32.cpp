#include "ex14_32.h"

StrBlobPtr &StrBlobPtr_ptr::operator*() const
{
    return *p;
}

StrBlobPtr *StrBlobPtr_ptr::operator->() const
{
    return &this->operator*();
}
