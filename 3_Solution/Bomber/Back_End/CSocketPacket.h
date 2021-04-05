#pragma once
#include <string>
#include "CUtils.h"
#include "Config.h"

class CSocketPacket
{
private:
	std::string m_data;
	//
	//
public:
	CSocketPacket(std::string _data) :m_data(_data) {};
	std::string GetData() const;
};

