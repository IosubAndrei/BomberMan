#pragma once
#include <list>
#include "CUser.h"

class CResponse
{
public:
	enum class ContainedAction
	{
		Register = 200,
		Login,
		Logout,
		GetDetails,
		GetAllDemands,
		GetAllWarnings,
		DeleteUser,
		ShutDownServer,
		ErrorMessage
	};

private:
	ContainedAction m_action;
	bool m_flag;
	int m_value;
	std::string m_text;
	std::list<std::string> m_stringList;
	std::string m_errorCaption;

public:
	CResponse(ContainedAction _action, bool _flag = false, int _value = 0, std::string _text = "", std::string _errorCaption = "") : m_action(_action), m_flag(_flag), m_value(_value), m_text(_text), m_errorCaption(_errorCaption) {};
	CResponse(ContainedAction _action, std::list<std::string> _stringList, bool _flag = false, int _value = 0, std::string _text = "", std::string _errorCaption = "") :m_action(_action), m_flag(_flag), m_value(_value), m_stringList(_stringList), m_text(_text), m_errorCaption(_errorCaption) {};
	ContainedAction GetAction() const;
	bool GetFlag() const;
	int GetValue() const;
	std::string GetText() const;
	std::list<std::string> GetStringList() const;
	std::string GetErrorCaption() const;
};

