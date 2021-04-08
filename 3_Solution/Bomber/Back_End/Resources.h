#pragma once
#include "Texture.h"
#include "Direction.h"
#include <array>
#include <vector>

enum class eFrameID
{
	ePlayerMoveUpStart = 263,
	ePlayerMoveUpEnd = 264,
	ePlayerMoveDownStart = 256,
	ePlayerMoveDownEnd = 258,
	ePlayerMoveRightStart = 259,
	ePlayerMoveRightEnd = 262,
	ePlayerMoveLeftStart = 259,
	ePlayerMoveLeftEnd = 262,
	eBombStart = 236,
	eBombEnd = 266,
	eExplosionStart = 284,
	eExplosionEnd = 254,
	eMovementSpeedPickUp = 254,
	eExtraBombPickUp = 220,
	eBox = 204
};

enum class eAnimationName
{
	ePlayerIdleUp = 0,
	ePlayerIdleDown,
	ePlayerIdleLeft,
	ePlayerIdleRight,
	ePlayerMoveUp,
	ePlayerMoveDown,
	ePlayerMoveRight,
	ePlayerMoveLeft,
	eBomb,
	eExplosion,
	eMovementSpeedPickUp,
	eExtraBombPickUp,
	eTotal
};

enum class eAnimationFlipped
{
	eFalse = 0,
	eTrue
};

enum class eAnimationRepeatable
{
	eFalse = 0,
	eTrue
};

struct AnimationDetails
{
	const eDirection direction;
	const int startFrameID;
	const int endFrameID;
	const bool flipped;
	const bool repeatable;

	AnimationDetails(eDirection type, eFrameID startFrameID, eFrameID endFrameID,
		eAnimationRepeatable repeatable = eAnimationRepeatable::eTrue, eAnimationFlipped flipped = eAnimationFlipped::eFalse);
};

class Textures : private NonCopyable
{
private:
	std::unique_ptr<Texture> m_tileSheet;
	bool m_loadedAllTextures = false;

public:
	const Texture& getTIleSheet() const;
	bool loadAllTExtures();
};


class Animations : private NonCopyable
{

};
