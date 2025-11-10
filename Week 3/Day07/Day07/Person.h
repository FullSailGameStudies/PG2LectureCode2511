#pragma once
#include <string>
class Person
{
	//what kind of data describes a person? (fields)
	// name, age, weight, height, ?
	// 
	// FIELDS (data members)
	//  WHO (code) can see it?
	//  for fields, generally make them PRIVATE (protect the data)
	//  Naming conventions:
	//		m_sName, m_name, mName, _name, name_
	//	use one of these and be consistent
	void simple(std::string& name)
	{
		//changing the local variable only
		//impacts this scope
		std::string nm;

		//changing the parameter means
		//you MIGHT be changing a variable
		//in a different scope
		name = "steve";

		//changes the object
		name_ = "Steve Austin";
	}
private:
	std::string name_;
	int age_;
	
	//what can the class do? (methods - member functions)
	// eat, sleep, work, dance, sing, attack?, walk

public:
	//getters and setters can be defined in the header file
	//getters (accessors) methods
	//  PATTERN:
	//		the return type matches the type of the data
	//		no parameters
	//		const b/c they should NOT change the class
	//		usually just returns the field
	const std::string& GetName() const
	{
		return name_;
	}
	//ALTERNATIVE naming...
	int Age() const
	{
		return age_;
	}

	//setters (mutators)
	//	PATTERN:
	//		void return type
	//		1 parameter that matches the type of the field
	//		non-const b/c they change the object
	//		usually has some logic to protect the field (validation)
	void SetName(const std::string& name)
	{
		if (name.size() > 0 && name.size() < 32)
		{
			name_ = name;
		}
	}
	void Age(int age)
	{
		if (age > 0 && age < 120)
		{
			age_ = age;
		}
	}
};

