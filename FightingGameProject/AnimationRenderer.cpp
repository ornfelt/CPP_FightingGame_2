#include "AnimationRenderer.h"

namespace RB::Render
{
	AnimationRenderer::AnimationRenderer()
	{

	}
	AnimationRenderer::~AnimationRenderer()
	{
		for (int i = 0; i < _loadedAnimations.size(); i++)
		{
			delete _loadedAnimations[i];
		}
	}

	void AnimationRenderer::Init()
	{
		//NONE by default (will render nothing)
		LoadAnimation(0, 0, 0, RB::Sprites::SpriteID::NONE);
	}

	void AnimationRenderer::LoadAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, RB::Sprites::SpriteID spriteID)
	{
		LoadedAnimation* loaded = new LoadedAnimation(widthIndexes, heightIndexes, totalIndexes, spriteID);

		_loadedAnimations.push_back(loaded);
	}

	LoadedAnimation* AnimationRenderer::GetAnimation(RB::Sprites::SpriteID spriteID)
	{
		for (int i = 0; i < _loadedAnimations.size(); i++)
		{
			if (_loadedAnimations[i]->GetSpriteID() == spriteID)
			{
				return _loadedAnimations[i];
			}
		}

		return nullptr;
	}
}