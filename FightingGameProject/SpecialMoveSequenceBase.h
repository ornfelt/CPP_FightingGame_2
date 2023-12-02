#pragma once

#include <vector>

#include "iSpecialMoveSequence.h"

namespace RB::Input
{
	class SpecialMoveSequenceBase : public iSpecialMoveSequence
	{
	public:
		SpecialMoveSequenceBase() = default;
		virtual ~SpecialMoveSequenceBase() override;

	public:
		virtual bool IsMatching(RB::Players::PlayerID playerID) override;
		virtual RB::Input::SpecialMoveType GetSpecialMoveType() override;

	protected:
		std::vector<RB::Input::PlayerInput> _vecSequence;
		std::vector<RB::Input::PlayerInput> _vecSequenceFromRightSide;
		SpecialMoveType _specialMoveType = RB::Input::SpecialMoveType::NONE;
	};
}