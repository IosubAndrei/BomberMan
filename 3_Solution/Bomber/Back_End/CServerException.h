#pragma once
#include "CException.h"

class CServerException :
    public CException
{
private:
    void InitByCode(unsigned int _code);
    std::string GetHeader() const;

public:
    CServerException(unsigned int _code);
    virtual ~CServerException() {};
};

