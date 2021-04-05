#pragma once
#include <string>
#include "CLogFile.h"

class CLogger
{
public:
	enum class LogType
	{
		Debug,
		Info,
		Warnng,
		Error,
		FatalError
	};

private:
	CLogFile* logFile;

public:
	CLogger() :logFile(nullptr) {};
	CLogger(std::string _filename);
	~CLogger();
	void SetFile(std::string _filename);
	void LogText(LogType _type, std::string _message) const;
	void PrintText(LogType _type, std::string _message) const;
	std::string GetTypeString(LogType _type) const;
};

