#pragma once
#include<string>
#include "Exceptions.h"

class IException
{
public:
	enum WarningSeverity
	{
		Warning,
		Error,
		FatalError
	};
	virtual std::string GetInfo() const = 0;
	virtual void Print() const = 0;
	virtual void Log() const = 0;
};

