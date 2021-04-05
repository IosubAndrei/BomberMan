#include "CMiscException.h"
#include "Exceptions.h"

CMiscException::CMiscException(unsigned int _code)
{
	this->InitByCode(_code);
}

void CMiscException::InitByCode(unsigned int _code)
{
	switch (_code)
	{
		case ERROR_BASE:
			this->InitBySeverityAndMessage(WarningSeverity::Warning, "Aceasta este o exceptie misc pentru eroarea de baza.");
			break;
		case ERROR_UNKNOWN_ERROR_CODE:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Codul misc nu a fost gasit.");
			break;
		case ERROR_LOGGER_CANT_OPEN_FILE:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Instanta misc a fost deja creata.");
			break;
		case ERROR_LOGGING_FILE_NOT_SET:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Logging file-ul nu este setat.");
			break;
		case ERROR_UNKNOWN_LOGGING_TYPE:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Tip necunoscut de logging.");
			break;
		case ERROR_CANNOT_CONNECT_TO_DATABASE:
			this->InitBySeverityAndMessage(WarningSeverity::Error, "Nu putem deschide conexiunea cu baza de date.");
			break;
		default:
			throw CMiscException(ERROR_UNKNOWN_ERROR_CODE);
			return;
	}
	this->m_code = _code;
}

std::string CMiscException::GetHeader() const
{
	return std::string("Misc exceptie.");
}