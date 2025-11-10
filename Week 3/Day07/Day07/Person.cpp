#include "Person.h"

//use the member initialization list to initialize the fields
Person::Person(const std::string& name, int age) :
	name_(name),
	age_(age)
{
	//OK
	//name_ = name;
	//age_ = age;
}