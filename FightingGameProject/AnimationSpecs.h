#pragma once
#include "SpriteID.h"
#include "LoadedSprite.h"

namespace RB::Render
{
	class AnimationSpecs
	{
	public:
		AnimationSpecs() = default;
		~AnimationSpecs() = default;

	public:
		uint32_t mX_TileCount = 0;
		uint32_t mY_TileCount = 0;
		uint32_t mTotalSprites = 0;
		uint32_t mSkipFixedUpdates = 0;
		olc::vf2d mRenderSize = { 0.0f, 0.0f };
		olc::vf2d mRenderOffset = { 0.0f, 0.0f };
		RB::Sprites::SpriteID mSpriteID = RB::Sprites::SpriteID::NONE;
		RB::Sprites::LoadedSprite* mLoadedSprite = nullptr;
	};
}