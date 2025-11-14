// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pistol.h"
#include <vector>
#include "Knife.h"


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
};


class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	//static methods
	//  there is NO 'this' pointer
	//  can ONLY access other static members
	static void reporting()
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//non-static methods:
	//there's a hidden parameter called 'this'
	// 'this' is a pointer to the object that called the method
	// can access non-static AND static members
	void vehicleInfo() 
	{
		std::cout << "Model Year: " << mModelYear << "\n";
	}
};
//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;

Car* StackMemory()
{
	//stack memory
	int x = 10;
	int* ptr = &x;
	std::cout << ptr << "\t" << *ptr << "\n";
	Car myCar(1988);
	Car* pCar = &myCar;
	std::cout << pCar << "\t" << pCar->mModelYear << "\n";
	return pCar;
}//all these variables are gone after the method

Car* HeapMemory()
{
	//heap memory (dynamic memory)
	//  ' = new' creates heap memory
	//  so that it lives longer than the method
	//  will be allocated until you delete it
	Car* heapCar = new Car(1984);
	return heapCar;
}

int main()
{
	Car* sCar = StackMemory();
	std::cout << sCar->mModelYear << "\n";//???unpredictable
	Car* hCar = HeapMemory();
	std::cout << hCar->mModelYear << "\n";

	//if you do NOT delete heap memory when you're done with it,
	//you are leaking memory
	//deallocates the memory. now that spot can be used for something else.
	delete hCar;
	hCar = nullptr;
	//read access violation
	//std::cout << hCar->mModelYear << "\n";

	if (hCar != nullptr)
	{
		std::cout << hCar->mModelYear << "\n";
	}

	Car gsCar(2025);
	Car todaysCar(gsCar);
	Car jCar(2024);
	jCar = todaysCar;//what happens. copies the data to jCar
	gsCar.vehicleInfo();//passes &gsCar for the 'this' pointer
	Car::reporting();

	Pistol pewpew(100, 200, 10, 5);
	Weapon wpn = pewpew;//what happens? copies ONLY the weapon parts of pewpew

	//what happens??? stores the memory address of pewpew
	//UPCASTING: taking a derived type (Pistol) and casting it to a base type (Weapon)
	//  ALWAYS safe b/c the compiler knows the relationship
	Weapon* pWpn = &pewpew;
	Weapon* pWpn2 = pWpn;
	std::cout << pWpn->range() << "\n";

	Knife stabby(3, 10, true);
	std::vector<Weapon*> wpns;
	wpns.push_back(&pewpew);
	wpns.push_back(&stabby);

	std::cout << "\n\nMy Inventory:\n";
	for (auto& wpn : wpns)
	{
		wpn->showMe();//run-time polymorphism
		std::cout << "\n";
	}


	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/

	{
		//memory on the heap
		std::unique_ptr<Pistol> uPistol =
			std::make_unique<Pistol>(200, 100, 10, 5);
		uPistol->showMe();

		
		std::vector<std::unique_ptr<Pistol>> pistols;
		pistols.push_back(std::move(uPistol));//transfer ownership
		uPistol->showMe();

	}//uPistol is auto-deleted here

	//1) no other pointer can be pointed to this pistol
	//   uPistol OWNS the memory exclusively
	//2) it is automatically deleted when it goes out of scope



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/




	/*
		╔══════════════════╗
		║  Static Members  ║
		╚══════════════════╝

		When calling a non-static method on a class, you must use a variable of that class.
		That's because the variable is passed in as the 'this' parameter.

		Static methods do not have a 'this' parameter therefore you call them on the
		class name itself.

		That's also why static methods cannot access non-static members.

	*/
	Car myRide(1988);
	Car::reporting();
	myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

	/*

		CHALLENGE:
		Add a static method to the Car class that returns an instance of the Car class.

	*/
}