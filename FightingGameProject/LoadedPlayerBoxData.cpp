#include "LoadedPlayerBoxData.h"

namespace RB::Collisions
{
	void LoadedPlayerBoxData::OnFixedUpdate()
	{
		for (auto i = _vecSpecs.begin(); i != _vecSpecs.end(); i++)
		{
			i->OnFixedUpdate();
		}
	}

	void LoadedPlayerBoxData::Add(PlayerBoxSpecs specs)
	{
		_vecSpecs.push_back(specs);

		RefreshIterators();
	}

	void LoadedPlayerBoxData::SetCharacterType(RB::Players::CharacterType characterType)
	{
		_characterType = characterType;
	}

	RB::Players::CharacterType LoadedPlayerBoxData::GetCharacterType()
	{
		return _characterType;
	}

	PlayerBoxSpecs* LoadedPlayerBoxData::GetSpecs(RB::Sprites::SpriteEnum spriteType)
	{
		for (auto i = _vecSpecs.begin(); i != _vecSpecs.end(); i++)
		{
			if (i->GetSpriteType() == spriteType)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	PlayerBox* LoadedPlayerBoxData::GetSpecs(RB::Sprites::SpriteEnum spriteType, unsigned int frame)
	{
		for (auto i = _vecSpecs.begin(); i != _vecSpecs.end(); i++)
		{
			if (i->GetSpriteType() == spriteType)
			{
				auto* vec = i->GetSelector()->GetVector_ptr();

				for (auto j = vec->begin(); j != vec->end(); j++)
				{
					if (j->mFrame == frame)
					{
						return &(*j);
					}
				}
			}
		}

		return nullptr;
	}

	void LoadedPlayerBoxData::EraseSpecs(RB::Sprites::SpriteEnum spriteType, unsigned int frame)
	{
		for (auto i = _vecSpecs.begin(); i != _vecSpecs.end(); i++)
		{
			if (i->GetSpriteType() == spriteType)
			{
				auto* vec = i->GetSelector()->GetVector_ptr();

				for (auto j = vec->begin(); j != vec->end(); j++)
				{
					if (j->mFrame == frame)
					{
						vec->erase(j);

						return;
					}
				}
			}
		}
	}

	void LoadedPlayerBoxData::RefreshIterators()
	{
		for (auto i = _vecSpecs.begin(); i != _vecSpecs.end(); i++)
		{
			i->GetSelector()->SetRefreshed(false);
		}
	}
}