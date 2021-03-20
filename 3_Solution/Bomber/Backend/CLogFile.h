#pragma once
#include <fstream>
#include<stdio.h>
#include<stdlib.h>
#include <string>

class CLogFile
{
private:
	std::string m_filename;
	FILE* openedFile;

public:
	CLogFile(std::string _filename, const char* _mode);
	~CLogFile() {};
	std::string GetFilename() const;
	std::ofstream GetOfstream() const;
	std::string GetContent() const;
};

