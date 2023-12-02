#include "P0_Seq_Hadouken.h"

namespace RB::Input::Sequences
{
	P0_Seq_Hadouken::P0_Seq_Hadouken(RB::Input::SpecialMoveType specialMoveType, const std::vector<PlayerInput>& vec)
	{
		_SetSequence(specialMoveType, vec);
		_SetSequenceForRightSide(vec);
	}

	bool P0_Seq_Hadouken::IsMatching(RB::Players::PlayerID playerID)
	{
		return false;
	}
}