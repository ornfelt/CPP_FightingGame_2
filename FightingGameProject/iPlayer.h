#pragma once
#include "olcPixelGameEngine.h"
#include "iState.h"
#include "PlayerID.h"
#include "AABB.h"
#include "SpriteID.h"

namespace RB::Players
{
	class iPlayer
	{
	public:
		iPlayer() = default;
		virtual ~iPlayer() = default;

	public:
		virtual void Init(PlayerID id, RB::States::iState* firstPlayerState) = 0;
		virtual void SetOtherPlayer(iPlayer* otherPlayer) = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual PlayerID GetPlayerID() = 0;
		virtual iPlayer* GetOtherPlayer() = 0;
		virtual bool OtherPlayerIsOnRightSide() = 0;
		virtual size_t GetStateMachineID() = 0;
		virtual void Move(olc::vi2d moveAmount) = 0;
		virtual olc::vi2d GetPosition() = 0;
		virtual void SetPosition(olc::vi2d pos) = 0;

	public:
		virtual olc::vi2d GetPlayerBox() = 0;
		virtual RB::Collisions::AABB GetAABB() = 0;
		virtual bool IsCollidingAgainstOtherPlayer() = 0;

	public:
		virtual void SetAirMomentum(olc::vf2d momentum) = 0;
		virtual void AddMomentum(olc::vf2d momentum) = 0;
		virtual olc::vf2d GetAirMomentum() = 0;

	public:
		virtual RB::Sprites::SpriteID GetSpriteID() = 0;
	};
}