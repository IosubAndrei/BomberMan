#pragma once
#include <string>

class CUser
{
public:

	enum UserType
	{
		User,
		Administrator,
		UnknownUserType
	};

protected:
	unsigned int m_userID;
	std::string m_username;
	std::string m_password;
	UserType m_type;
	bool m_status;

public:
	CUser(unsigned int _userID, std::string _username, std::string _password, UserType _type) :m_userID(_userID), m_username(_username), m_password(_password), m_status(false)
	{
	}
	virtual ~CUser() {};
	std::string GetUsername() const;
	unsigned int GetUserID() const;
	UserType GetType() const;
	bool GetStatus() const;
	unsigned int LoginWithPassword(std::string _password);
	void Logout();
};

