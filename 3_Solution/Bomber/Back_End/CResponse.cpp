#include "CResponse.h"

CResponse::ContainedAction CResponse::GetAction() const 
{
	return this->m_action;

}

bool CResponse::GetFlag() const 
{
	return this->m_flag;

}

int CResponse::GetValue() const 
{
	return this->m_value;

}

std::string CResponse::GetText() const 
{
	return this->m_text;

}

std::list<std::string> CResponse::GetStringList() const 
{
	return this->m_stringList;

}

std::string CResponse::GetErrorCaption() const 
{
	return this->m_errorCaption;

}