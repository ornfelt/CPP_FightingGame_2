#include "F0_Crouch_Punch_Weak.h"

#include "F0_Crouch_Idle.h" //avoid circular include

namespace RB::Fighter_0_States
{
	void F0_Crouch_Punch_Weak::OnEnter()
	{
		_spriteType = Sprites::SpriteType::fighter_0_crouch_punch_weak;

        AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::DetectHit());
		AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new Fighter_0_States::F0_Crouch_Idle()));

		EnterStateComponents();
	}

	void F0_Crouch_Punch_Weak::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Crouch_Punch_Weak::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Crouch_Punch_Weak::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}