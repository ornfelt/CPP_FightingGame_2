#include "HBoxData.h"

namespace RB::HBox
{
	HBoxData::HBoxData(std::string frameName, std::vector<RB::Collisions::AABB> vecAABB)
	{
		_frameName = frameName;
		_frame = _ParseFrame(frameName);

		for (auto i = vecAABB.begin(); i != vecAABB.end(); i++)
		{
			_selector.PushBack(*i);
		}
	}

	HBoxData::~HBoxData()
	{

	}

	void HBoxData::OnFixedUpdate()
	{
		_selector.OnFixedUpdate();
	}

	unsigned int HBoxData::GetFrame()
	{
		return _frame;
	}

	//const std::vector<RB::Collisions::AABB>& HBoxData::GetVecAABBs()
	//{
	//	const std::vector<RB::Collisions::AABB>& vec = _selector.GetVector();
	//
	//	return vec;
	//}

	RB::Collisions::AABB* HBoxData::GetSelectedAABB()
	{
		RB::Collisions::AABB* aabb = _selector.GetSelected();

		return aabb;
	}

	void HBoxData::UpSelection()
	{
		_selector.SelectUp();
	}

	void HBoxData::DownSelection()
	{
		_selector.SelectDown();
	}

	RB::Collisions::AABB& HBoxData::GetAABB(unsigned int index)
	{
		RB::Collisions::AABB* aabb = _selector.GetByIndex(index);

		return *aabb;
	}

	const std::string& HBoxData::GetFrameName()
	{
		return _frameName;
	}

	void HBoxData::SetFrameNameAndParse(const std::string& name)
	{
		_frameName = name;
		_frame = _ParseFrame(name);
	}

	void HBoxData::AddAABB(RB::Collisions::AABB aabb)
	{
		_selector.PushBack(aabb);
	}

	void HBoxData::DeleteSelectedAABB()
	{
		_selector.EraseSelected();
	}

	RB::iSelector<RB::Collisions::AABB>* HBoxData::GetSelector()
	{
		return &_selector;
	}

	unsigned int HBoxData::_ParseFrame(const std::string& str)
	{
		std::regex pattern("frame_");
		std::string replacement = "";
		std::string s = std::regex_replace(str, pattern, replacement);
		std::stringstream stream(s);
		unsigned int result;
		stream >> result;
		return result;
	}
}