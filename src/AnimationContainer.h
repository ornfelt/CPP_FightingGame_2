#pragma once

#include <string>

#include "JParser.h"
#include "AnimationObj.h"
#include "SpriteContainer.h"
#include "AnimationRenderer.h"

#include "iAnimationObj.h"

namespace RB::Render
{
	class AnimationContainer
	{
	public:
		AnimationContainer() = default;
		~AnimationContainer();

		void Init();
		void OnFixedUpdate();
		void OnUpdate();

	public:
		AnimationSpecs LoadAnimationSpecsFromJSON(std::string path);
		RB::Sprites::LoadedSprite* LoadSprite(std::string path, RB::Sprites::SpriteType spriteType);
		AnimationRenderer* LoadAnimation(std::string specsPath);
		void DeleteAnimationObjs(RB::Players::PlayerID playerID);
		std::vector<iAnimationObj*>::const_iterator DeleteAnimationObj(std::vector<iAnimationObj*>::const_iterator& it);
		iAnimationObj* GetCurrentAnimationObj(RB::Players::PlayerID playerID, RB::Sprites::SpriteType spriteType);
		iAnimationObj* GetCurrentAnimationObj(unsigned int index);
		iAnimationObj* InstantiateNewAnimationObj(RB::Players::iPlayer& player, RB::Sprites::SpriteType spriteType, RB::Sprites::PivotType pivotType);
		RB::Sprites::SpriteType GetSpriteType(RB::Players::PlayerID playerID);
		void AddNewAnimation(iAnimationObj* animationObj);
		const std::vector<iAnimationObj*>& GetVecCurrentAnimations();
		AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteType spriteType);

	protected:
		std::vector<iAnimationObj*> _vecCurrentAnimations; // current running animations
		RB::Sprites::SpriteContainer _spriteContainer;
		std::vector<AnimationRenderer*> _vecAnimationRenderers; // all loaded animations
	};
}
