#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:
	//a DECLARATION

	//const methods CANNOT change class members (ex. name_)
	void GetGrades(std::vector<float>& courseGrades)const;

	void PrintGrades(const std::vector<float>& courseGrades) const;

	const std::string& GetName() const { return name_; }
	void SetName(const std::string& name)
	{
		if (not name.empty())
		{
			name_ = name;
		}
	}

private:
	std::string name_;
};

