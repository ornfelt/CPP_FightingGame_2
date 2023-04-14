#include "PlayerAnimationObj.h"

namespace RB::Render
{
	PlayerAnimationObj::PlayerAnimationObj(RB::Players::iPlayer* owner, LoadedAnimation* loadedAnimation)
	{
		_player = owner;
		_loadedAnimation = loadedAnimation;

		_skipFixedUpdates.SetSkipFrames(_loadedAnimation->GetFixedUpdateSkipCount());
		_skipFixedUpdates.SetFunction(this, &PlayerAnimationObj::IncreaseAnimationIndex);
	}

	PlayerAnimationObj::~PlayerAnimationObj()
	{

	}

	void PlayerAnimationObj::OnFixedUpdate()
	{
		_skipFixedUpdates.OnFixedUpdate();
	}

	void PlayerAnimationObj::IncreaseAnimationIndex()
	{
		//std::cout << "increasing animation index for player " << (int)_player->GetPlayerID() << std::endl;

		unsigned int totalSprites = _loadedAnimation->GetTotalSprites();

		_currentIndex++;

		if (_currentIndex >= totalSprites)
		{
			_currentIndex = 0;
		}
	}

	olc::vf2d PlayerAnimationObj::GetSourceSize()
	{
		unsigned int xTiles = _loadedAnimation->GetXTileCount();
		unsigned int yTiles = _loadedAnimation->GetYTileCount();

		olc::vf2d sourceSize = { 0.0f, 0.0f };
		sourceSize.x = (float)_loadedAnimation->GetSpriteSize().x / (float)xTiles;
		sourceSize.y = (float)_loadedAnimation->GetSpriteSize().y / (float)yTiles;

		return sourceSize;
	}

	olc::vf2d PlayerAnimationObj::GetSourcePos(olc::vf2d sourceSize)
	{
		olc::vf2d sourcePos = { 0.0f, 0.0f };

		sourcePos.x = (_currentIndex % _loadedAnimation->GetXTileCount()) * sourceSize.x;
		sourcePos.y = (int32_t)floor(_currentIndex / _loadedAnimation->GetXTileCount()) * sourceSize.y;

		return sourcePos;
	}

	RB::Sprites::SpriteID PlayerAnimationObj::GetSpriteID()
	{
		return _loadedAnimation->GetSpriteID();
	}

	RB::Players::iPlayer* PlayerAnimationObj::GetPlayer()
	{
		return _player;
	}

	void PlayerAnimationObj::RenderAnimation()
	{
		if (_loadedAnimation->GetSpriteID() == RB::Sprites::SpriteID::NONE)
		{
			return;
		}

		AnimationInfo animationInfo;

		animationInfo.mCurrentIndex = _currentIndex;
		animationInfo.mSourceSize = GetSourceSize();
		animationInfo.mSourcePos = GetSourcePos(animationInfo.mSourceSize);
		animationInfo.mWorldPos = _player->GetPosition();
		animationInfo.mRenderSize = olc::vf2d{ 300.0f, 150.0f }; //temp sprite size
		animationInfo.mPivotType = RB::Sprites::PivotType::BOTTOM_CENTER;

		_loadedAnimation->RenderAnimation(animationInfo);
	}
}