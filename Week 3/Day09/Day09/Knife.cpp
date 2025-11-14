#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	Weapon::showMe();
	std::cout << "Serrated: " << serrated_ << "\n";
}