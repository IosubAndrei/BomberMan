#pragma once
#include "CException.h"

class CClientException: public CException
{
private:
	void InitByCode(unsigned int _code);
	std::string GetHeader() const;

public:
	CClientException(unsigned int _code);
	virtual ~CClientException() {};
};

