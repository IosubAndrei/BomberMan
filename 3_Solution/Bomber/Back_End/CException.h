#pragma once
#include "IException.h"
class CException :
	public IException
{
protected:
	WarningSeverity m_severity;
	unsigned int m_code;
	std::string m_mesage;

	void InitBySeverityAndMessage(WarningSeverity, std::string);
public:
	CException() {};
	virtual ~CException() {};
	std::string GetInfo() const override;
	void Print() const override;
	void Log() const override;
};

