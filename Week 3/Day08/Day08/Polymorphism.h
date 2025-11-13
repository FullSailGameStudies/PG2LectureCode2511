#pragma once
#include <iostream>
#include <string>

/*

	COMPILE-TIME Polymorphism

	Method Overloading:
		- changing the number of parameters
		- changing the types of the parameters

*/
class Calculator
{
public:
	int add(int n1, int n2);
	int add(int n1, int n2, int n3);
	float add(float f1, float f2);
	double add(double d1, double d2);
};


/*

	COMPILE-TIME Polymorphism

	Operator Overloading

*/
class Account
{
private:

public:
	double mBalance;

	Account operator+(Account& other)
	{
		Account acct;
		acct.mBalance = mBalance + other.mBalance;
		return acct;
	}
};




/*

	RUNTIME Polymorphism

	method overriding

*/
class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	//step 1: mark the base method with 'virtual'
	//  virtual tells the compiler that this method MIGHT be 
	//  overridden in a derived class
	//	DO NOT mark every base method as virtual
	//	only mark them virtual if they need to be overridden
	virtual void print()
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
	//step 2: create a method in the derived
	//	that matches the signature of the base method
	void print()
	{
		//step 3: write the code to either EXTEND or FULLY override the base

		//Extension override:
		//	we want to ADD to the base behavior
		//  call the base method
		base::print();
		std::cout << "\tHello derived " << mStr << "\n";

		//Full override:
		//  we do NOT want any of the base behavior
		//  do NOT call the base method
	}
};
