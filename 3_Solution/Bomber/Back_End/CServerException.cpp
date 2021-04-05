#include "CServerException.h"

CServerException::CServerException(unsigned int _code)
{
	this->InitByCode(_code);
}

void CServerException::InitByCode(unsigned int _code)
{
	switch (_code) {
		case ERROR_SERVER_BASE:
			this->InitBySeverityAndMessage(WarningSeverity::Warning, "Aceasta este o exceptie server pentru eroarea de baza.");
			break;
		case ERROR_SERVER_UNKNOWN_ERROR_CODE:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Codul serverului nu a fost gasit.");
			break;
		case ERROR_SERVER_INSTANCE_IS_CREATED:
			this->InitBySeverityAndMessage(WarningSeverity::Warning, "Instanta serverului a fost deja creata.");
			break;
		case ERROR_SERVER_INSTANCE_DOESNT_EXIST:
			this->InitBySeverityAndMessage(WarningSeverity::Warning, "Instanta serverului nu este creata.");
			break;
		case ERROR_SERVER_USERNAME_NOT_AVAILABLE:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Username-ul nu este disponibila.");
			break;
		case ERROR_SERVER_USER_NOT_FOUND:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Userul nu a fost gasit.");
			break;
		case ERROR_SERVER_IS_ALREADY_ON:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Serverul este deja pornit.");
			break;
		case ERROR_SERVER_IS_ALREADY_OFF:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Serverul este deja oprit.");
			break;
		case ERROR_LOGGER_CANT_OPEN_FILE:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Acest fisier nu exista.");
			break;
		default:
			throw CServerException(ERROR_SERVER_UNKNOWN_ERROR_CODE);
			return;
	}
	this->m_code = _code;
}

std::string CServerException::GetHeader() const
{
	return std::string("exceptie Server.");
}