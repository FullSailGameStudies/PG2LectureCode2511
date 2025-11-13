#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	Weapon::showMe();
	std::cout << "Rounds: " << rounds_ << " Mag Capacity: " << magCapacity_ << "\n";
}
int Pistol::calcDamage()
{
	return Weapon::calcDamage();
}