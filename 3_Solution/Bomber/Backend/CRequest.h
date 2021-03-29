#pragma once
#include "CUser.h"

class CRequest
{
public:
	enum class ContainedAction
	{
		Register = 100,
		Login,
		Logout,
		GetDetails,
		GetAllDemands,
		GetAllWarnings,
		DeleteUser,
		RequestFile,
		ShutDownServer
	};

private:
	ContainedAction m_action;
	std::string m_username;
	std::string m_password;
	std::string m_friendUsername;
	int m_value;
	std::string m_filename;

public:
	CRequest(ContainedAction _action, std::string _username = "", std::string _password = "",
		std::string _friendUsername = "", int _value = 0, std::string _filename = "") :m_action(_action),
		m_username(_username), m_password(_password), m_friendUsername(_friendUsername), m_value(_value),
		m_filename(_filename) {};

	ContainedAction GetAction() const;
	std::string GetUsername() const;
	std::string GetPassword() const;
	std::string GetFriendUsername() const;
	int GetValue() const;
	std::string GetFilename() const;
};

