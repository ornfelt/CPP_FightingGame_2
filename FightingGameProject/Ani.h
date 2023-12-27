#pragma once
#include "iAni.h"
#include "iAnimationObj.h"
#include "AnimationObj.h"

#include "Sprites.h"
#include "AnimationLoader.h"

namespace RB::Render
{
	class Ani : public RB::Render::iAni
	{
	public:
		Ani() = default;
		~Ani() override;

		virtual void Init() override;
		virtual void OnFixedUpdate() override;
		virtual void OnUpdate() override;

		virtual void LoadSprite(std::string path, RB::Sprites::SpriteEnum spriteEnum) override;
		virtual void LoadAnimation(AnimationSpecs specs, RB::Sprites::SpriteEnum spriteEnum) override; //requires sprite to be loaded first
		virtual void DeleteAnimationObj(RB::Players::PlayerID playerID) override;
		virtual void DeleteAnimationObj(unsigned int index) override;
		virtual iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteEnum spriteEnum) override;
		virtual iAnimationObj* GetCurrentAnimationObj(unsigned int index) override;
		virtual iAnimationObj* InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteEnum playerSpriteEnum, RB::Sprites::PivotType pivotType) override;
		virtual RB::Sprites::SpriteEnum GetSpriteEnum(RB::Players::PlayerID playerID) override;
		virtual void PushCurrentAnimation(iAnimationObj* animationObj) override;
		virtual unsigned int GetCurrentAniCount() override;
		virtual AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteEnum spriteEnum) override;

	protected:
		Sprites _sprites;
		AnimationLoader _animationLoader;
		std::vector<iAnimationObj*> _vecCurrentAnimations;
	};
}