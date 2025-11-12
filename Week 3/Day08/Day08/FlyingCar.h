#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:

	FlyingCar(int year, std::string make, std::string model,
		      int altitude, int maxAltitude) :
		//base ctor calls here
		Car(year, make, model),//base ctor is called first
		altitude_(altitude), 
		maxAltitude_(0)
	{
		//derived ctor runs second
		MaxAltitude(maxAltitude);
	}

	int Altitude() const { return altitude_; }
	void Altitude(int altitude)
	{
		if (altitude >= 0 && altitude <= maxAltitude_)
		{
			altitude_ = altitude;
		}
	}
	int MaxAltitude() const { return maxAltitude_; }
	void MaxAltitude(int maxAlt)
	{
		if (maxAlt > 0 && maxAlt <= 500)
		{
			maxAltitude_ = maxAlt;
		}
	}

private:
	int altitude_, maxAltitude_;

public:
};

