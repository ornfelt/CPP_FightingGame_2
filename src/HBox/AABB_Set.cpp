#include "AABB_Set.h"

namespace RB::HBox
{
	AABB_Set::AABB_Set(std::string frameName)
	{
		_frameName = frameName;
		_frame = RB::JSON::JParser::ParseFrame(frameName);
	}

	AABB_Set::AABB_Set(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB)
	{
		_frameName = frameName;
		_frame = RB::JSON::JParser::ParseFrame(frameName);

		for (auto i = vecAABB.begin(); i != vecAABB.end(); i++)
		{
			_selector.PushBack(*i);
		}
	}

	AABB_Set::~AABB_Set()
	{

	}

	void AABB_Set::OnFixedUpdate()
	{
		_selector.OnFixedUpdate();
	}

	void AABB_Set::OnUpdate()
	{
		_selector.OnUpdate();
	}

	RB::iSelector<RB::Collisions::AABB>* AABB_Set::GetSelector()
	{
		return &_selector;
	}

	unsigned int AABB_Set::GetFrame()
	{
		return _frame;
	}

	const std::string& AABB_Set::GetFrameName()
	{
		return _frameName;
	}

	void AABB_Set::SetFrameNameAndParse(const std::string& name)
	{
		_frameName = name;
		_frame = RB::JSON::JParser::ParseFrame(name);
	}
}
