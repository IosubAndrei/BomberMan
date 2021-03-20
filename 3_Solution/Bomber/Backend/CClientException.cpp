#include "CClientException.h"
#include "Exceptions.h"

CClientException::CClientException(unsigned int _code)
{
	this->InitByCode(_code);
}

void CClientException::InitByCode(unsigned int _code)
{
	switch (_code)
	{
	case ERROR_CLIENT_BASE:
		this->InitBySeverityAndMessage(WarningSeverity::Warning, "Aceasta este o exceptie client pentru eroarea de baza.");
		break;
	case ERROR_CLIENT_UNKNOWN_ERROR_CODE:
		this->InitBySeverityAndMessage(WarningSeverity::Warning, "Codul clientului nu a fost gasit.");
		break;
	case ERROR_CLIENT_INSTANCE_IS_CREATED:
		this->InitBySeverityAndMessage(WarningSeverity::Warning, "Instanta clientului a fost deja creata.");
		break;
	case ERROR_CLIENT_INSTANCE_DOESNT_EXIST:
		this->InitBySeverityAndMessage(WarningSeverity::Warning, "Instanta clientului nu este creata.");
		break;
	case ERROR_CLIENT_NO_USER_IS_LOGGED:
		this->InitBySeverityAndMessage(WarningSeverity::Warning, "Niciun client nu este loggat pentru a realiza actiunea.");
		break;
	case ERROR_CLIENT_NO_ADMINISTRATOR_PRIVILEGES:
		this->InitBySeverityAndMessage(WarningSeverity::Warning, "Acest utilizator nu are privilegii de administrator.");
		break;
	default:
		throw CClientException(ERROR_CLIENT_UNKNOWN_ERROR_CODE);
		return;
	}
	this->m_code = _code;

}

std::string CClientException::GetHeader() const
{
	return std::string("Exceptie client.");
}
