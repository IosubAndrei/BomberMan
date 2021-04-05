#include "CUser.h"

#pragma region Getters

std::string CUser::GetUsername() const {

	return this->m_username;
}

unsigned int CUser::GetUserID() const {

	return this->m_userID;
}

CUser::UserType CUser::GetType() const {

	return this->m_type;
}

bool CUser::GetStatus() const {

	return this->m_status;
}

#pragma endregion

#pragma region Setters

unsigned int CUser::LoginWithPassword(std::string password) {

	if (this->m_password == password ) {
		this->m_status = true;
		return this->m_userID;
	}
	return UINT_MAX;

}

void CUser::Logout() {

	this->m_status = false;
}

#pragma endregion