#pragma once
#include <iostream>

#include "FunctionCode.h"

using namespace std;
class Protocol
{
public:
	Protocol(FunctionCode fCode, string fProtocolString);
	~Protocol() {}

	inline FunctionCode getFunctionCode() { return code; }
	inline string getProtocolString() { return protocolString; }
private:
	string protocolString;
	FunctionCode code;
};

