#pragma once

#include "ControllerT.h"

#include "iPlayer.h"
#include "PlayerID.h"

namespace RB::Players
{
	class iPlayerController : public RB::Controllers::ControllerT<iPlayerController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual iPlayer* AddPlayer(iPlayer* player) = 0;

	public:
		virtual iPlayer* GetPlayerOnIndex(unsigned int index) = 0;
		virtual iPlayer* GetPlayerOnID(PlayerID id) = 0;
		virtual iPlayer* GetPlayerOnStateMachineID(unsigned int id) = 0;
		virtual iPlayer* GetOtherPlayer(iPlayer* currentPlayer) = 0;
	};
}
