#include "SpecialMoveSequenceBase.h"

namespace RB::Input
{
	SpecialMoveSequenceBase::~SpecialMoveSequenceBase()
	{

	}

	bool SpecialMoveSequenceBase::IsMatching(RB::Players::PlayerID playerID)
	{
		return false;
	}

	RB::Input::SpecialMoveType SpecialMoveSequenceBase::GetSpecialMoveType()
	{
		return _specialMoveType;
	}

	void SpecialMoveSequenceBase::_SetSequence(SpecialMoveType specialMoveType, const std::vector<RB::Input::PlayerInput>& vec)
	{
		_specialMoveType = specialMoveType;

		for (size_t i = 0; i < vec.size(); i++)
		{
			_vecSequence.push_back(vec[i]);
		}
	}

	void SpecialMoveSequenceBase::_SetSequenceForRightSide(const std::vector<RB::Input::PlayerInput>& vec)
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			if (vec[i] == PlayerInput::MOVE_LEFT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_RIGHT);
			}
			else if (vec[i] == PlayerInput::MOVE_DOWN_LEFT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_DOWN_RIGHT);
			}
			else if (vec[i] == PlayerInput::MOVE_RIGHT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_LEFT);
			}
			else if (vec[i] == PlayerInput::MOVE_DOWN_RIGHT)
			{
				_vecSequenceFromRightSide.push_back(PlayerInput::MOVE_DOWN_LEFT);
			}
			else
			{
				_vecSequenceFromRightSide.push_back(vec[i]);
			}
		}
	}
}