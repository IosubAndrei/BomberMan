#include "CLogFile.h"
#include "CMiscException.h"

CLogFile::CLogFile(std::string _filename, const char* _mode) :m_filename(_filename)
{
	this->openedFile = fopen(_filename.c_str(), _mode);
	if (this->openedFile == nullptr)
		throw CMiscException(ERROR_LOGGER_CANT_OPEN_FILE);

}

CLogFile::~CLogFile()
{
	fclose(this->openedFile);

}

std::string CLogFile::GetFilename() const
{
	return this->m_filename;

}

std::ofstream CLogFile::GetOfstream() const
{
	return std::ofstream(this->openedFile);

}

std::string CLogFile::GetContent() const
{
	std::string phrase;
	char* content;
	int size;

	fseek(this->openedFile, 0, SEEK_END);
	size = ftell(this->openedFile);
	fseek(this->openedFile, 0, SEEK_SET);
	content = new char[size + 1];
	fread(content, size, 1, this->openedFile);
	phrase = std::string(content);
	delete content;
	return phrase;

}