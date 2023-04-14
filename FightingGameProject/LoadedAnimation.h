#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteID.h"
#include "PivotType.h"
#include "LoadedSprite.h"
#include "CurrentCam.h"
#include "AnimationInfo.h"

namespace RB::Render
{
	class LoadedAnimation
	{
	public:
		LoadedAnimation(unsigned int xTileCount, unsigned int yTileCount, unsigned int totalSprites, unsigned int skipFixedUpdates, RB::Sprites::SpriteID spriteID, RB::Sprites::LoadedSprite* loadedSprite);
		~LoadedAnimation();

	public:
		RB::Sprites::SpriteID GetSpriteID();
		unsigned int GetXTileCount();
		unsigned int GetYTileCount();
		unsigned int GetTotalSprites();

	public:
		void RenderAnimation(AnimationInfo animationInfo);
		unsigned int GetFixedUpdateSkipCount();
		olc::vi2d GetSpriteSize();

	private:
		unsigned int _xTileCount;
		unsigned int _yTileCount;
		unsigned int _totalSprites;
		unsigned int _skipFixedUpdates;
		RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
		RB::Sprites::LoadedSprite* _loadedSprite = nullptr;
	};
}