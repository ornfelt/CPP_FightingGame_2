#include "EntityController.h"

namespace RB::Entities
{
	EntityController::EntityController()
	{
		cout << "constructing EntityController" << endl;
	}

	EntityController::~EntityController()
	{
		cout << "destroying EntityController" << endl;
	}

	void EntityController::Init()
	{
		//SetName("EntityController");
	}

	void EntityController::OnUpdate()
	{

	}

	void EntityController::OnFixedUpdate()
	{

	}
}