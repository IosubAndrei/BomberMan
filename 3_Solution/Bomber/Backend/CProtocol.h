#pragma once
#include <string>
#include "CSocketPacket.h"
#include "CRequest.h"
#include "CResponse.h"

class CProtocol
{
public:

	// Packet format
	static void AddToSocketData(std::string& socketData, std::string dataBlock);
	static std::string GetNextDataBlock(std::string& socketData, bool removeAfterFind = true);
	static std::string GetLastDataBlock(std::string& socketData);

	//Verify type
	static bool IsRequest(CSocketPacket& socketPacket);

	//	Conversie CSocketPacket -> std::string
	static std::string MoveToLowerLayer(CSocketPacket& socketPacket);
	static CSocketPacket MoveToUpperLayer(std::string& socketData);

	//	Conversie CSocletPacket -> CRequest
	static CSocketPacket MoveRequestToLowerLayer(CRequest& request);
	static CRequest MoveRequestToUpperLayer(CSocketPacket& socketPacket);

	//	Conversie CSocketPacket -> CResponse
	static CSocketPacket MoveResponseToLowerLayer(CResponse& reponse);
	static CResponse MoveResponseToUpperLayer(CSocketPacket& socketPacket);

};

