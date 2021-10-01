#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <string>

class Parser
{
private:
	Parser();
	~Parser();
	Parser(Parser& copyInstance) = delete;

	static Parser* instance;
public:

	static Parser* getInstance();
	static void destroyInstance();

	std::vector<std::string> protocoliseString(int functionID, std::vector<std::string>& vectString); // process the vector to simplify: adds int into first element
	std::string parseString(std::vector<std::string> unparsedVectorOfStrings, char stringDelimiter); // ex: 1$my$protocol
	std::vector<std::string> unparseString(std::string parsedString, char stringDelimiter); //breaks down strings like 2$your$protocol
	std::string hash_string(std::string sir, int nr_ordine, char delim);
};

