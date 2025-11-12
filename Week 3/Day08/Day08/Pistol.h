#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds, int magCapacity) :
		Weapon(range,damage),
		rounds_(rounds), 
		magCapacity_(magCapacity)
	{
	}

	int Rounds() const { return rounds_; }
	int MagCapacity() const { return magCapacity_; }

	void Rounds(int rounds)
	{
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}
	void MagCapacity(int magCapacity)
	{
		if (magCapacity >= 0 && magCapacity <= 50)
			magCapacity_ = magCapacity;
	}

private:
	int rounds_, magCapacity_;

};

