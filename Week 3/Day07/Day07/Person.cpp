#include "Person.h"
#include <iostream>

void Person::Eat(const std::string& food)
{
	std::cout << "I'm hungry! Let's eat some " << food << "\n";
}

//use the member initialization list to initialize the fields
Person::Person(const std::string& name, int age) :
	name_(name),
	age_(age)
{
	//OK
	//name_ = name;
	//age_ = age;
}