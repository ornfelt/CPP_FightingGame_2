#include "P0_Wince.h"

namespace RB::PlayerStates
{
	void P0_Wince::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_wince);

		//AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		//AddStateComponent(new RB::PlayerStateComponents::WhileMovingForward());

		EnterStateComponents();
	}

	void P0_Wince::OnExit()
	{

	}

	void P0_Wince::OnUpdate()
	{

	}

	void P0_Wince::OnFixedUpdate()
	{

	}
}