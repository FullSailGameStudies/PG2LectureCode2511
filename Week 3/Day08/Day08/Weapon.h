#pragma once
class Weapon //abstract
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	virtual void showMe();
	virtual int calcDamage() = 0;//pure virtual

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

