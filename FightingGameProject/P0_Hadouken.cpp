#include "P0_Hadouken.h"

namespace RB::PlayerStates
{
	void P0_Hadouken::OnEnter()
	{
		StandardInit(RB::Sprites::SpriteEnum::fighter_0_hadouken);

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(_ownerPlayer->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::TriggerIdleOnAnimationEnd());

		EnterStateComponents();
	}

	void P0_Hadouken::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Hadouken::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Hadouken::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}