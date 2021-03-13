#include <iostream>
#include "CException.h"
#include "Exceptions.h"

void CException::InitBySeverityAndMessage(WarningSeverity _severity, std::string _message)
{
	this->m_severity = _severity;
	this->m_mesage = _message;
}

std::string CException::GetInfo() const
{
	std::string returned;

	returned = returned + "Exited with code: ";
	//returned = returned + std::string(this->m_code);
	//
	//
	return returned;
}

void CException::Print() const {

}

void CException::Log() const {


}
