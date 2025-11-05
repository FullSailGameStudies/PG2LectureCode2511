// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip>

enum class Weapon
{
	Sword, Axe, Spear, Mace
};

const int NOT_FOUND = -1;

/// <summary>
/// Searches a vector of ints for a specific number using
/// the linear search algorithm.
/// </summary>
/// <param name="nums">The vector to search</param>
/// <param name="searchNumber">The number to find</param>
/// <returns>-1 if NOT found. The index if found.</returns>
int LinearSearch(const std::vector<int>& nums, int searchNumber)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (searchNumber == nums[i])
		{
			return i;
		}
	}
	return NOT_FOUND;//0-size()-1 is a valid range. -1 indicates not found
}

void PrintGrades(const std::map<std::string, double>& course)
{
	std::cout << "\n\nPG2 2511\n";
	for (auto& [student, grade] : course)
	{
		std::cout << std::setw(10) << std::left << student << " ";

		Console::SetForegroundColor(
			//ternary operator (shorthand for if-else)
			(grade < 59.5) ? ConsoleColor::Red :
			(grade < 69.5) ? ConsoleColor::Yellow :
			(grade < 79.5) ? ConsoleColor::Blue :
			(grade < 89.5) ? ConsoleColor::Magenta :
			ConsoleColor::Green
		);
		std::cout << std::setw(7) << std::right << grade << '\n';
		Console::Reset();
	}
	std::cout << "\n\n";
}

int main()
{
	/*
		╔═════════╗
		║Searching║
		╚═════════╝

		There are 2 ways to search a vector: linear search or binary search

		CHALLENGE:

			write a method to linear search the numbers list.
				The method should take 2 parameters: vector of ints to search, int to search for.
				The method should return -1 if NOT found or the index if found.

			The algorithm:
				1) start at the beginning of the vector
				2) compare each item in the vector to the search item
				3) if found, return the index
				4) if reach the end of the vector, return -1 which means not found

	*/
	std::vector<int> numbers = { 0,1,2,3,4,5,6 };
	int searchNumber = 6;
	int foundIndex = LinearSearch(numbers, searchNumber);
	if (foundIndex == NOT_FOUND)
	{
		std::cout << searchNumber << " was not found.\n";
	}
	else
	{
		std::cout << searchNumber << " was found at index " << foundIndex << "\n";
	}
	std::cout << "\n\n";



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Creating a map  ]

		map<TKey, TValue>  - an associative collection.
			TKey is a placeholder for the type of the keys.
			TValue is a placeholder for the type of the values.

		When you want to create a map variable,
			1) replace TKey with whatever type of data you want to use for the keys
			2) replace TValue with the type you want to use for the values


		[  Adding items to a map  ]

		There are 2 ways to add items to a map:
		1) using the insert method.
		2) using [key] = value
	*/
	std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

	//returns an iterator and a bool. 
	//if the key is already in the map, it will NOT insert it -- the bool will be false.
	auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
	if (inserted.second == false) //meaning not inserted
		std::cout << "The key was already in the map. It was not inserted.\n";
	else
		std::cout << "The key was inserted in the map.\n";

	dorasBackpack[Weapon::Axe] = 3;
	dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map



	std::map<std::string, float> menu;
	//2 ways to add data to a map:
	//1) map[key] = value;
	menu["cookies"] = 2.99f;
	menu["milk"] = 4.99f;
	menu["eggnog"] = 8.99f;
	menu["eggnog"] = 6.99f;//overwrites any existing value
	menu["tiramisu"] = 9.99f;

	//2) map.insert(key-value pair);
	std::pair<std::string, float> menuPair =
		std::make_pair("hot chocolate", 5.99f);
	menu.insert(menuPair);
	menuPair.second = 6.49f;
	auto wasInserted = menu.insert(menuPair);//does NOT overwrite the value
	if (wasInserted.second)
	{
		std::cout << "Item inserted.\n";
	}
	else
	{
		std::cout << "Item is already on the menu. Do you want to change the price?\n";
	}

	std::cout << "\nG's Cafe\n";
	for (auto it = menu.begin(); it != menu.end(); it++)
	{
		std::cout << it->first;
		Console::SetCursorLeft(15);
		std::cout << it->second << "\n";
	}
	std::cout << "\n\n";
	for (auto& kvp : menu)
	{
		std::cout << std::setw(15) << std::left << kvp.first << " ";
		std::cout << std::setw(7) << std::right << kvp.second << '\n';
	}

	std::cout << "\n\n";
	for (auto& [menuItem, itemPrice] : menu)
	{
		std::cout << std::setw(15) << std::left << menuItem << " ";
		std::cout << std::setw(7) << std::right << itemPrice << '\n';
	}

	std::string itemToFind = "eggnog";//Arby's
	// do NOT loop to find a key (linear search)
	// use the find method (binary search)
	auto wasFound = menu.find(itemToFind);
	if (wasFound != menu.end()) //did it find it?
	{
		//using [key] causes another search to happen
		//menu[itemToFind] *= 1.10;

		//use the iterator if you have it. you've already found it.
		wasFound->second *= 1.10;

		//use structured bindings to get more meaningful variable names
		const auto& [itemName, itemPrice] = *wasFound;
		std::cout << itemName << " costs " << itemPrice << "\n";
	}
	else
	{
		std::cout << itemToFind << " is not on the menu. Try Arby's\n";
	}
	/*
		CHALLENGE:

			Create a map that stores names (string) and grades. Call the variable grades.
			Add students and grades to your map.

	*/
	std::map<std::string, double> grades;

	std::vector<std::string> students =
	{
		"Garrett", "Alex", "Jacob", "Diego", "Ashley",
		"Kristoffer", "Aidan", "Akeem", "Cole", "David",
		"James", "Monica", "Wesley"
	};
	srand(time(NULL));//seed rand()
	for (auto& student : students)
	{
		grades[student] = rand() % 10001 / 100.0;
	}

	std::cout << "\n\nGarrett's Grade: " << grades["Garrett"] << "\n";
	//ONLY use [key] to access the value IF you know the key is in the map
	//otherwise, it will ADD the key
	//std::cout << "Steve's Grade: " << grades["Steve"] << "\n\n\n";

	//loop over the grades map and print the students with their grades
	PrintGrades(grades);




	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Looping over a map  ]

		You should use a ranged-based for loop when needing to loop over the entire map.

	*/
	for (auto const& [key, val] : dorasBackpack) //requires C++ 20
	{
		switch (key)
		{
		case Weapon::Sword:
			std::cout << "Sword: ";
			break;
		case Weapon::Axe:
			std::cout << "Axe: ";
			break;
		case Weapon::Spear:
			std::cout << "Spear: ";
			break;
		case Weapon::Mace:
			std::cout << "Mace: ";
			break;
		default:
			break;
		}
		std::cout << val << "\n";
	}


	/*
		CHALLENGE:

			Loop over your grades map and print each student name and grade.

	*/



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Checking for a key in a map  ]

		use the find method to check if the key is in the map

		will return map.end() if NOT found.

	*/
	std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
	if (foundIter == dorasBackpack.end()) //meaning it was NOT found
	{
		std::cout << "Dora did not find any maces.\n";
	}
	else
	{
		//can safely grab the value for the key
		std::cout << "Dora found " << foundIter->second << " Maces\n";
	}



	/*
		CHALLENGE:

			look for a specific student in the map.
			If the student is found, print out the student's grade
			else print out a message that the student was not found

	*/




	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Updating a value for a key in a map  ]

		To update an exisiting value in the map, use the [ ]


	*/
	dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



	/*
		CHALLENGE:

			Pick any student and curve the grade (add 5) that is stored in the grades map

	*/
}