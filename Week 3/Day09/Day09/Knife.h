#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:

	Knife(int range, int damage, bool serrated_) : 
		Weapon(range,damage),
		serrated_(serrated_)
	{
	}
	void showMe() override;

private:
	bool serrated_;
};

