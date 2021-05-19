#include "Parser.h"

Parser* Parser::instance = nullptr;

Parser::Parser()
{

}

Parser::~Parser()
{
	destroyInstance();
}

Parser* Parser::getInstance()
{
    if (instance == nullptr)
        instance = new Parser;
    return instance;
}

void Parser::destroyInstance()
{
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

std::vector<std::string> Parser::protocoliseString(int functionID, std::vector<std::string>& vectString)
{
    vectString.insert(vectString.begin(), 1, std::to_string(functionID));
    return vectString;
}

std::string Parser::parseString(std::vector<std::string> unparsedVectorOfStrings, char stringDelimiter)
{
    std::string parsedString;

    for (int index = 0; index < unparsedVectorOfStrings.size(); index++)
    {
        parsedString += unparsedVectorOfStrings[index];
        if (!(index == unparsedVectorOfStrings.size() - 1))
            parsedString += stringDelimiter;
    }

    return parsedString;
}

std::vector<std::string> Parser::unparseString(std::string parsedString, char stringDelimiter)
{
    std::vector<std::string> tokens;
    std::stringstream check1(parsedString);

    std::string intermediate;

    while (getline(check1, intermediate, stringDelimiter))
    {
        tokens.push_back(intermediate);
    }

    return tokens;
}