#pragma once
#include "CException.h"
class CMiscException :
    public CException
{
private:
	void InitByCode(unsigned int code);
	std::string GetHeader() const;
public:
	CMiscException(unsigned int code);
	virtual ~CMiscException() {};
};

