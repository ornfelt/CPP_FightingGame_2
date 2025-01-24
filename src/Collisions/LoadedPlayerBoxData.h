#pragma once

#include <vector>

#include "PlayerBox.h"
#include "PlayerBoxSpecs.h"

#include "../Players/CharacterType.h"

namespace RB::Collisions
{
	class LoadedPlayerBoxData
	{
	public:
		LoadedPlayerBoxData(Players::CharacterType characterType);
		LoadedPlayerBoxData(Players::CharacterType characterType, PlayerBoxSpecs specs);
		~LoadedPlayerBoxData() = default;

	public:
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void Add(PlayerBoxSpecs specs);
		Players::CharacterType GetCharacterType();
		PlayerBoxSpecs* GetSpecs(Sprites::SpriteType spriteType);
		PlayerBox* GetSpecs(Sprites::SpriteType spriteType, unsigned int frame);
		void EraseSpecs(Sprites::SpriteType spriteType, unsigned int frame);
		void RefreshIterators();

	private:
		std::vector<PlayerBoxSpecs> _vecSpecs;
		Players::CharacterType _characterType = Players::CharacterType::NONE;
	};
}