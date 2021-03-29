#include "CRequest.h"

CRequest::ContainedAction CRequest::GetAction() const {

	return this->m_action;

}

std::string CRequest::GetUsername() const {

	return this->m_username;

}

std::string CRequest::GetPassword() const {

	return this->m_password;

}

std::string CRequest::GetFriendUsername() const {

	return this->m_friendUsername;

}

int CRequest::GetValue() const {

	return this->m_value;

}

std::string CRequest::GetFilename() const {

	return this->m_filename;

}
