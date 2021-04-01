#include <string>
#include "CProtocol.h"
#include "Config.h"
#include "CMiscException.h"
#include "CEnumConverter.h"

void CProtocol::AddToSocketData(std::string& socketData, std::string dataBlock)
{
	if (socketData == "") socketData = dataBlock;
	else
		socketData = socketData + PROTOCOL_DELIMITATOR + dataBlock;
}

std::string CProtocol::GetNextDataBlock(std::string& socketData, bool removeAfterFind)
{
	int start = 0;
	int end = socketData.length();
	int count = 0;
	std::string token;
	bool flag = false;

	for (int i = 0; i < socketData.length(); i++)
	{
		if (socketData[i] == PROTOCOL_DELIMITATOR)
		{
			end = i;
			flag = true;
			token = socketData.substr(start, end - start);
			if (removeAfterFind)
				socketData = socketData.substr(end + 1, socketData.length());
			break;
		}
	}

	if (!flag)
	{
		token = socketData;
		if (removeAfterFind)
			socketData = "";
	}
	return token;
}

std::string CProtocol::GetLastDataBlock(std::string& socketData)
{
	int start = 0;
	int end = socketData.length();
	int count = 0;
	std::string token;

	for (int i = socketData.length(); i >= 0; i++)
	{
		if (socketData[i] == PROTOCOL_DELIMITATOR)
		{
			start = i;
			token = socketData.substr(start + 1, end - start);
			socketData = socketData.substr(0, start);
			break;
		}
	}
	return token;
}

bool CProtocol::IsRequest(CSocketPacket& socketPacket)
{
	std::string data;

	data = socketPacket.GetData();
	if (data[0] == '1') return true;
	else
		return false;
}

std::string CProtocol::MoveToLowerLayer(CSocketPacket& socketPacket)
{
	std::string data;

	CProtocol::AddToSocketData(data, socketPacket.GetData());
	return data;
}

CSocketPacket CProtocol::MoveToUpperLayer(std::string& socketData)
{
	CSocketPacket* created;
	std::string data;

	data = socketData;

	created = new CSocketPacket(data);
	return *created;
}

CSocketPacket CProtocol::MoveRequestToLowerLayer(CRequest& request)
{
	CSocketPacket* created;
	std::string data;

	CProtocol::AddToSocketData(data, CEnumConverter<CRequest::ContainedAction>::StringifyType(request.GetAction()));
	CProtocol::AddToSocketData(data, request.GetUsername());
	CProtocol::AddToSocketData(data, request.GetPassword());
	CProtocol::AddToSocketData(data, request.GetFriendUsername());
	CProtocol::AddToSocketData(data, std::to_string(request.GetValue()));
	CProtocol::AddToSocketData(data, request.GetFilename());
	created = new CSocketPacket(data);
	return *created;
}

CRequest CProtocol::MoveRequestToUpperLayer(CSocketPacket& socketPacket)
{
	CRequest* created;
	std::string dataCopy;
	CRequest::ContainedAction action;
	std::string username;
	std::string password;
	std::string friendUsername;
	std::string filename;
	int value;

	dataCopy = socketPacket.GetData();
	action = CEnumConverter<CRequest::ContainedAction>::UnstringifyType(CProtocol::GetNextDataBlock(dataCopy));
	username = CProtocol::GetNextDataBlock(dataCopy);
	password = CProtocol::GetNextDataBlock(dataCopy);
	friendUsername = CProtocol::GetNextDataBlock(dataCopy);
	value = std::stoi(CProtocol::GetNextDataBlock(dataCopy));
	filename = CProtocol::GetNextDataBlock(dataCopy);
	created = new CRequest(action, username, password, friendUsername, value, filename);
	return *created;
}

CSocketPacket CProtocol::MoveResponseToLowerLayer(CResponse& response)
{
	CSocketPacket* created;
	std::list<std::string> stringList;
	std::string data;

	CProtocol::AddToSocketData(data, CEnumConverter<CResponse::ContainedAction>::StringifyType(response.GetAction()));
	CProtocol::AddToSocketData(data, std::to_string(response.GetFlag()));
	CProtocol::AddToSocketData(data, std::to_string(response.GetValue()));
	CProtocol::AddToSocketData(data, response.GetText());
	stringList = response.GetStringList();
	CProtocol::AddToSocketData(data, std::to_string(stringList.size()));
	for (auto& it : stringList)
	{
		CProtocol::AddToSocketData(data, it);
	}
	CProtocol::AddToSocketData(data, response.GetErrorCaption());
	created = new CSocketPacket(data);
	return *created;
}

CResponse CProtocol::MoveResponseToUpperLayer(CSocketPacket& socketPacket)
{
	CResponse* created;
	std::string copyData;
	CResponse::ContainedAction action;
	bool flag;
	int value;
	std::string text;
	std::list<std::string> stringList;
	std::string errorCaption;
	int number;

	copyData = socketPacket.GetData();
	action = CEnumConverter<CResponse::ContainedAction>::UnstringifyType(CProtocol::GetNextDataBlock(copyData));
	flag = std::stoi(CProtocol::GetNextDataBlock(copyData));
	value = std::stoi(CProtocol::GetNextDataBlock(copyData));
	text = CProtocol::GetNextDataBlock(copyData);
	number = std::stoi(CProtocol::GetNextDataBlock(copyData));
	for (int i = 0; i < number; i++)
	{
		stringList.push_back(CProtocol::GetNextDataBlock(copyData));
	}
	errorCaption = CProtocol::GetNextDataBlock(copyData);
	created = new CResponse(action, stringList, flag, value, text, errorCaption);
	return *created;
}