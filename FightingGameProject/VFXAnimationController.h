#pragma once
#include "iVFXAnimationController.h"

#include "Ani.h"

namespace RB::Render
{
	class VFXAnimationController : public RB::Render::iVFXAnimationController
	{
	public:
		VFXAnimationController();
		~VFXAnimationController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void InstantiateAnimation(RB::Sprites::SpriteEnum spriteEnum) override;

	private:
		Ani _ani;
	};
}