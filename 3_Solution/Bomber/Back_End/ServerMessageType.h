#pragma once

enum class eServerMessageType
{
	eInvalidMoveRequest = 0,
	eInitializeClientID,
	eInitialGameData,
	ePlayerMove,
	ePlayerMovePosition,
	eNewPlayerPosition,
	ePlayerBombPlacementRequest,
	eValidBombPLacementRequest,
	ePlaceBomb,
	eBombExplosion,
	ePlayerDisconnected,
	eRequestDisconnection,
	ePathToRender,
	//
	eSpawnMovementPickup,
	eMovementPickUpCollision
};