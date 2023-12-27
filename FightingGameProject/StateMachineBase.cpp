#include "StateMachineBase.h"

namespace RB::States
{
	unsigned int StateMachineBase::stateMachinesCreated = 0;

	StateMachineBase::StateMachineBase()
	{
		stateMachinesCreated++;
		_stateMachineID = stateMachinesCreated;
	}

	StateMachineBase::~StateMachineBase()
	{
		if (_currentState != nullptr)
		{
			_currentState->OnExit();

			delete _currentState;
			_currentState = nullptr;
		}
	}

	void StateMachineBase::Init(iState* state)
	{
		_currentState = state;
		_currentState->SetStateMachineID(_stateMachineID);
		_currentState->OnEnter();
	}

	void StateMachineBase::OnUpdate()
	{
		if (!_currentState->IsTransitioning())
		{
			_currentState->OnUpdate();
		}
	}

	void StateMachineBase::OnFixedUpdate()
	{
		if (!_currentState->IsTransitioning())
		{
			_currentState->OnFixedUpdate();
			_currentState->AddCumulatedFixedUpdate();
		}

		_MakeTransition();
	}

	/// <summary>
	/// do not use new here (ONLY use a StateComponent for this function)
	/// </summary>
	void StateMachineBase::QueueNextState(iState* state)
	{
		if (state == nullptr)
		{
			return;
		}

		if (!_currentState->IsTransitioning())
		{
			_currentState->SetIsTransitioning(true);

			_nextState = state;
			_nextState->SetIsInQueue(true);
		}
	}

	/// <summary>
	/// use when NOT getting next state from a StateComponent
	/// </summary>
	/// <param name="state"></param>
	void StateMachineBase::OverrideNextState(RB::States::iState* state)
	{
		//deleting next state that is set by a StateComponent
		if (_nextState != nullptr)
		{
			_currentState->DeleteNextState(_nextState->GetCreationID());
		}

		_currentState->SetIsTransitioning(false);

		QueueNextState(state);
	}

	unsigned int StateMachineBase::GetID()
	{
		return _stateMachineID;
	}

	iState* StateMachineBase::GetCurrentState()
	{
		return _currentState;
	}

	bool StateMachineBase::IsTransitioning()
	{
		return _currentState->IsTransitioning();
	}

	void StateMachineBase::_MakeTransition()
	{
		if (_currentState->IsTransitioning())
		{
			//exit current state first
			_currentState->OnExit();

			//enter next state
			_nextState->SetStateMachineID(_stateMachineID);
			_nextState->OnEnter();

			//clean up last so statecomponents don't delete next state
			delete _currentState;
			_currentState = nullptr;

			_currentState = _nextState;
			_nextState = nullptr;
		}
	}
}