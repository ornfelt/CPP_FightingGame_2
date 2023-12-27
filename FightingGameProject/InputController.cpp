#include "InputController.h"

namespace RB::Input
{
	InputController::~InputController()
	{
		_ClearAllBuffers(RB::Players::PlayerID::PLAYER_1);
		_ClearAllBuffers(RB::Players::PlayerID::PLAYER_2);
	}

	void InputController::Init()
	{
		_totalInputTypes = static_cast<unsigned int>(PlayerInput::COUNT);

		_vecKeyBindings.reserve((unsigned int)PlayerInput::COUNT);

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_UP, olc::W });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_DOWN, olc::S });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_LEFT, olc::A });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_RIGHT, olc::D });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_UP, olc::U });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_DOWN, olc::J });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_LEFT, olc::H });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_RIGHT, olc::K });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::ATTACK_WEAK_PUNCH, olc::E });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_2, PlayerInput::ATTACK_WEAK_PUNCH, olc::I });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_LEFT, olc::LEFT });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_RIGHT, olc::RIGHT });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_UP, olc::UP });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::MOVE_CAM_DOWN, olc::DOWN });

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::CAM_ZOOM_OUT, olc::COMMA });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::NONE, PlayerInput::CAM_ZOOM_IN, olc::PERIOD });
	}

	void InputController::OnUpdate()
	{
		_UpdateInputBuffer(RB::Players::PlayerID::PLAYER_1);
		_UpdateInputBuffer(RB::Players::PlayerID::PLAYER_2);

		_AddDiagBuffer(RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_UP, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_UP_LEFT);
		_AddDiagBuffer(RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_UP, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_UP_RIGHT);
		_AddDiagBuffer(RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_DOWN_LEFT);
		_AddDiagBuffer(RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_DOWN_RIGHT);

		_AddDiagBuffer(RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_UP, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_UP_LEFT);
		_AddDiagBuffer(RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_UP, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_UP_RIGHT);
		_AddDiagBuffer(RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_DOWN_LEFT);
		_AddDiagBuffer(RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_DOWN_RIGHT);

		_UpdateDiagBufferRelease(RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_UP, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_UP_LEFT);
		_UpdateDiagBufferRelease(RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_UP, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_UP_RIGHT);
		_UpdateDiagBufferRelease(RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_DOWN_LEFT);
		_UpdateDiagBufferRelease(RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_DOWN_RIGHT);

		_UpdateDiagBufferRelease(RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_UP, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_UP_LEFT);
		_UpdateDiagBufferRelease(RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_UP, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_UP_RIGHT);
		_UpdateDiagBufferRelease(RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_LEFT, PlayerInput::MOVE_DOWN_LEFT);
		_UpdateDiagBufferRelease(RB::Players::PlayerID::PLAYER_2, PlayerInput::MOVE_DOWN, PlayerInput::MOVE_RIGHT, PlayerInput::MOVE_DOWN_RIGHT);

		_DestroyOldBuffers(RB::Players::PlayerID::PLAYER_1);
		_DestroyOldBuffers(RB::Players::PlayerID::PLAYER_2);
	}

	void InputController::OnFixedUpdate()
	{
		_TriggerSpecialMove(RB::Players::PlayerID::PLAYER_1);
		_TriggerSpecialMove(RB::Players::PlayerID::PLAYER_2);

		for (auto i = _vecP1_InputObjs.begin(); i != _vecP1_InputObjs.end(); ++i)
		{
			(*i)->OnFixedUpdate();
		}
		
		for (auto i = _vecP2_InputObjs.begin(); i != _vecP2_InputObjs.end(); ++i)
		{
			(*i)->OnFixedUpdate();
		}
	}

	olc::HWButton InputController::GetKeyBinding(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		for (auto i = _vecKeyBindings.begin(); i != _vecKeyBindings.end(); ++i)
		{
			if ((*i).GetPlayerID() == playerID)
			{
				if ((*i).GetPlayerInput() == playerInput)
				{
					olc::Key key = (*i).GetKey();

					olc::HWButton button = olc::Platform::ptrPGE->GetKey(key);

					return button;
				}
			}
		}

		return olc::HWButton();
	}

	iInputObj* InputController::GetInputOBJ_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				return (*i);
			}
		}

		return nullptr;
	}

	iInputObj* InputController::GetInputObj_LIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.rbegin(); i != vec.rend(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				return (*i);
			}
		}

		return nullptr;
	}

	iInputObj* InputController::GetUnused_Special_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				if ((*i)->IsUsedAsSpecial() == false)
				{
					return (*i);
				}
			}
		}

		return nullptr;
	}

	iInputObj* InputController::GetUnused_Movement_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				if ((*i)->IsUsedAsMovement() == false)
				{
					return (*i);
				}
			}
		}

		return nullptr;
	}

	bool InputController::IsHeld(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		std::vector<RB::Input::iInputObj*>* vec = nullptr;

		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			vec = &_vecP1_InputObjs;
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			vec = &_vecP2_InputObjs;
		}
		else
		{
			return false;
		}

		//reverse iterate
		for (auto i = vec->rbegin(); i != vec->rend(); ++i)
		{
			if ((*i)->GetPlayerInputType() == playerInput)
			{
				if (!(*i)->IsReleased())
				{
					return true;
				}
			}
		}

		return false;
	}

	unsigned int InputController::GetTotalInputCount(RB::Players::PlayerID playerID)
	{
		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return _vecP1_InputObjs.size();
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return _vecP2_InputObjs.size();
		}

		return 0;
	}

	iInputObj* InputController::GetInputByIndex(RB::Players::PlayerID playerID, unsigned int index)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		if (vec.size() > index)
		{
			return vec[index];
		}

		return nullptr;
	}

	void InputController::_UpdateInputBuffer(RB::Players::PlayerID playerID)
	{
		for (unsigned int i = 0; i < _totalInputTypes; i++)
		{
			PlayerInput input = (PlayerInput)i;

			olc::HWButton button = GetKeyBinding(playerID, input);

			if (button.bPressed || button.bHeld)
			{
				iInputObj* obj = GetInputObj_LIFO(playerID, input);

				//add new obj if first time pressed
				if (obj == nullptr)
				{
					_AddNewInputBuffer(playerID, input);
				}

				//add 2nd obj on top of existing obj
				else
				{
					if (obj->IsReleased())
					{
						_AddNewInputBuffer(playerID, input);
					}
				}
			}

			//set release status so 2nd obj can be added
			else if (button.bReleased)
			{
				_UpdateReleaseStatus(playerID, input);
			}
		}
	}

	void InputController::_AddNewInputBuffer(RB::Players::PlayerID playerID, PlayerInput input)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		iInputObj* newObj = new InputObj(input, RB::gameFrameCount, RB::gameFrameLoopCount);

		vec.push_back(newObj);

		_OnSpecialMove(playerID, input);
	}

	/// <summary>
	/// Check every time a punch or kick is pressed
	/// </summary>
	void InputController::_OnSpecialMove(RB::Players::PlayerID playerID, PlayerInput input)
	{
		if (RB::Input::iSpecialMovesController::instance == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(playerID);

		if (player->IsInSpecialMoveStatus())
		{
			return;
		}

		if (input == PlayerInput::ATTACK_WEAK_PUNCH || input == PlayerInput::ATTACK_WEAK_KICK)
		{
			RB::Input::SpecialMoveType specialMove = RB::Input::iSpecialMovesController::instance->GetSpecialMove(playerID);

			if (specialMove != SpecialMoveType::NONE)
			{
				std::vector<SpecialMoveType>& vec = _GetSpecialMoves(playerID);

				vec.push_back(specialMove);
			}
		}
	}

	void InputController::_UpdateReleaseStatus(RB::Players::PlayerID playerID, PlayerInput input)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			if ((*i)->GetPlayerInputType() == input)
			{
				(*i)->SetReleasedStatus(true);
			}
		}
	}

	void InputController::_AddDiagBuffer(RB::Players::PlayerID playerID, RB::Input::PlayerInput input0, RB::Input::PlayerInput input1, RB::Input::PlayerInput resultInput)
	{
		const std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		iInputObj* obj0 = nullptr;
		iInputObj* obj1 = nullptr;

		for (auto i = vec.rbegin(); i != vec.rend(); ++i)
		{
			if ((*i)->GetPlayerInputType() == input0)
			{
				obj0 = (*i);
			}

			if ((*i)->GetPlayerInputType() == input1)
			{
				obj1 = (*i);
			}

			if (obj0 != nullptr && obj1 != nullptr)
			{
				break;
			}
		}

		if (obj0 != nullptr && obj1 != nullptr)
		{
			if (!obj0->IsReleased() && !obj1->IsReleased())
			{
				iInputObj* existing = GetInputObj_LIFO(playerID, resultInput);

				if (existing == nullptr)
				{
					_AddNewInputBuffer(playerID, resultInput);
				}
				else if (existing->IsReleased())
				{
					_AddNewInputBuffer(playerID, resultInput);
				}

				//destroy existing straight direction buffers
				//destroy both
				if (obj0->IsPressedOnSameFrameAs(obj1))
				{
					_DestroyBuffer(playerID, obj0->GetPlayerInputType(), obj0->GetGameFrameCount(), obj0->GetGameFrameLoopCount());
					_DestroyBuffer(playerID, obj1->GetPlayerInputType(), obj1->GetGameFrameCount(), obj1->GetGameFrameLoopCount());
				}
				//destroy the latter
				else if (obj0->IsPressedEarlierThan(obj1))
				{
					_DestroyBuffer(playerID, obj1->GetPlayerInputType(), obj1->GetGameFrameCount(), obj1->GetGameFrameLoopCount());
				}
				//destroy the latter
				else
				{
					_DestroyBuffer(playerID, obj0->GetPlayerInputType(), obj0->GetGameFrameCount(), obj0->GetGameFrameLoopCount());
				}
			}
		}
	}

	void InputController::_UpdateDiagBufferRelease(RB::Players::PlayerID playerID, RB::Input::PlayerInput input0, RB::Input::PlayerInput input1, RB::Input::PlayerInput resultInput)
	{
		olc::HWButton button0 = GetKeyBinding(playerID, input0);
		olc::HWButton button1 = GetKeyBinding(playerID, input1);

		if (!button0.bHeld || !button1.bHeld)
		{
			const std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

			for (auto i = vec.begin(); i != vec.end(); ++i)
			{
				if ((*i)->GetPlayerInputType() == resultInput)
				{
					(*i)->SetReleasedStatus(true);
				}
			}
		}
	}

	void InputController::_DestroyOldBuffers(RB::Players::PlayerID playerID)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (int i = vec.size() - 1; i >= 0; i--)
		{
			//only destroy when key is released
			if (vec[i]->IsReleased())
			{
				if (vec[i]->GetFixedUpdateCount() >= 60)
				{
					delete vec[i];
					vec[i] = nullptr;

					std::vector<iInputObj*>::iterator it;
					it = vec.begin();
					vec.erase(it + i);
				}
			}
		}
	}

	/// <summary>
	/// erase all that matches
	/// </summary>
	void InputController::_DestroyBuffer(RB::Players::PlayerID playerID, RB::Input::PlayerInput playerInput, unsigned int gameFrame, unsigned int gameFrameLoop)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (int i = vec.size() - 1; i >= 0; i--)
		{
			if (vec[i]->GetPlayerInputType() == playerInput)
			{
				if (vec[i]->GetGameFrameCount() == gameFrame && vec[i]->GetGameFrameLoopCount() == gameFrameLoop)
				{
					delete vec[i];
					vec[i] = nullptr;

					std::vector<iInputObj*>::iterator it;
					it = vec.begin();
					vec.erase(it + i);
				}
			}
		}
	}

	/// <summary>
	/// erase just one
	/// </summary>
	void InputController::_DestroyBuffer(RB::Players::PlayerID playerID, iInputObj* inputObj)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (int i = vec.size() - 1; i >= 0; i--)
		{
			if (vec[i]->GetPlayerInputType() == inputObj->GetPlayerInputType())
			{
				if (vec[i]->IsPressedOnSameFrameAs(inputObj))
				{
					delete vec[i];
					vec[i] = nullptr;

					std::vector<iInputObj*>::iterator it;
					it = vec.begin();
					vec.erase(it + i);

					return;
				}
			}
		}
	}

	void InputController::_ClearAllBuffers(RB::Players::PlayerID playerID)
	{
		std::vector<iInputObj*>& vec = _GetInputObjs(playerID);

		for (auto i = vec.begin(); i != vec.end(); ++i)
		{
			delete (*i);
			(*i) = nullptr;
		}

		vec.clear();
	}

	std::vector<iInputObj*>& InputController::_GetInputObjs(RB::Players::PlayerID playerID)
	{
		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return _vecP1_InputObjs;
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return _vecP2_InputObjs;
		}

		return _vecNone_InputObjs;
	}

	std::vector<SpecialMoveType>& InputController::_GetSpecialMoves(RB::Players::PlayerID playerID)
	{
		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return _vecP1_SpecialMoves;
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return _vecP2_SpecialMoves;
		}

		return _vecNone_SpecialMoves;
	}

	void InputController::_TriggerSpecialMove(RB::Players::PlayerID playerID)
	{
		std::vector<SpecialMoveType>& vec = _GetSpecialMoves(playerID);

		if (!vec.empty())
		{
			RB::States::iState* state = RB::Input::iSpecialMovesController::instance->GetState(vec[0]);

			RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(playerID);

			player->GetStateMachine()->OverrideNextState(state);

			//clear all (only trigger the first one because it's impossible to queue 2 special moves in a single update)
			vec.clear();
		}
	}
}