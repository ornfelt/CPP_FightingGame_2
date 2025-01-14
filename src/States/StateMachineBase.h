#pragma once

#include "iStateMachine.h"
#include "iState.h"

namespace RB::States
{
	class StateMachineBase : public iStateMachine
	{
	public:
		static unsigned int stateMachinesCreated;

	public:
		StateMachineBase();
		virtual ~StateMachineBase() override;

	public:
		virtual void Init(iState* state) override;
		virtual void OnUpdate() override;
		virtual void OnFixedUpdate() override;

	public:
		virtual bool QueueNextState(iState* state) override;
		virtual bool OverrideNextState(RB::States::iState* state) override;
		virtual unsigned int GetID() override;
		virtual iState* GetCurrentState() override;
		virtual bool IsTransitioning() override;
		virtual void LockTransition(bool) override;

	protected:
		virtual void _MakeTransition() override;

		unsigned int _stateMachineID = 0;
		iState* _currentState = nullptr;
		iState* _nextState = nullptr;
		bool _lockTransition = false;
	};
}
