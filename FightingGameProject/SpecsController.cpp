#include "SpecsController.h"

namespace RB::Players::Specs
{
	SpecsController::~SpecsController()
	{

	}

	void SpecsController::Init()
	{
		_LoadMoveSpecs("MoveSpecs/Aku_moveSpecs.moveSpecs", RB::Players::CharacterType::AKU);
	}

	void SpecsController::OnUpdate()
	{

	}

	void SpecsController::OnFixedUpdate()
	{

	}

	MoveSpecs SpecsController::GetMoveSpecs(RB::Players::CharacterType characterType)
	{
		for (size_t i = 0; i < _vecMoveSpecs.size(); i++)
		{
			if (_vecMoveSpecs[i].mCharacterType == characterType)
			{
				return _vecMoveSpecs[i];
			}
		}

		std::cout << "no specs found" << std::endl;

		return MoveSpecs(characterType);
	}

	MoveSpecs SpecsController::_LoadMoveSpecs(std::string path, RB::Players::CharacterType characterType)
	{
		std::string str = RB::JSON::LoadJSONFile(path);

		const char* arrChar = str.c_str();

		struct json_value_s* jRoot = json_parse(arrChar, strlen(arrChar));
		struct json_object_s* jObj = json_value_as_object(jRoot);

		struct json_object_element_s* rootElement = RB::JSON::GetElementNFromObj(*jObj, 0); //aku move specs

		struct json_object_element_s* e0 = RB::JSON::GetElementInsideElement(*rootElement); //first element
		int32_t walk_Forward_Speed = RB::JSON::GetInt32_FromElement(*e0);

		struct json_object_element_s* e1 = e0->next;
		int32_t walk_Back_Speed = RB::JSON::GetInt32_FromElement(*e1);

		struct json_object_element_s* e2 = e1->next;
		int32_t jumpUp_totalFrames = RB::JSON::GetInt32_FromElement(*e2);

		struct json_object_element_s* e3 = e2->next;
		float_t jumpUp_speedMultiplier = RB::JSON::GetFloat_FromElement(*e3); 

		struct json_object_element_s* e4 = e3->next;
		int32_t jumpUp_Forward_totalFrames = RB::JSON::GetInt32_FromElement(*e4);

		struct json_object_element_s* e5 = e4->next;
		float_t jumpUp_Forward_speedMultiplier = RB::JSON::GetFloat_FromElement(*e5);

		MoveSpecs specs;
		specs.mCharacterType = characterType;
		specs.mWalk_Forward_Speed = walk_Forward_Speed;
		specs.mWalk_Back_Speed = walk_Back_Speed;
		specs.mJumpUp_totalFrames = jumpUp_totalFrames;
		specs.mJumpUp_speedMultiplier = jumpUp_speedMultiplier;
		specs.mJumpUp_Forward_totalFrames = jumpUp_Forward_totalFrames;
		specs.mJumpUp_Forward_speedMultiplier = jumpUp_Forward_speedMultiplier;

		_vecMoveSpecs.push_back(specs);

		return specs;
	}
}