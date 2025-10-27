#include "Menu.h"
#include <iostream>

//method DEFINITION
//requires a "ClassName::" prefixed to the method name
void Menu::AddMenuItem(std::string itemToAdd)
{
	menuItems.push_back(itemToAdd);
}

void Menu::ShowMenu()
{
	std::cout << "\n\nMenu: \n";
	std::cout << "\nfor loop\n";
	for (int i = 0; i < menuItems.size(); i++)
	{
		std::cout << menuItems[i] << "\n";
	}

	//range-based (foreach) loop
	std::cout << "\nrange-based for loop\n";
	for (std::string item : menuItems)
	{
		std::cout << item << "\n";
	}

	//an iterator is an object that "points" into the vector
	//provides access to an item in the vector
	//knows how to move to the next item
	// 2 methods for iterators:
	// begin() - gives an iterator to the first item in the vector
	// end() - gives an iterator the the item AFTER the last item

	//use * to access the item it points to

	std::cout << "\n iterator for loop\n";
	for (std::vector<std::string>::iterator iter = menuItems.begin(); iter != menuItems.end(); iter++)
	{
		std::cout << *iter << "\n";
	}
}

void Menu::RemoveItem(std::string itemToRemove)
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		//if we find a match...
		if (itemToRemove == menuItems[i])
		{
			//remove the item
			//erase REQUIRES an iterator
			//to get an iterator to the item, we use begin() + index
			menuItems.erase(menuItems.begin() + i);
			break;//exits the loop
		}
	}

	for (std::vector<std::string>::iterator iter = menuItems.begin(); iter != menuItems.end(); iter++)
	{
		//if we find a match...
		if (itemToRemove == *iter)
		{
			//remove the item
			//erase REQUIRES an iterator
			//to get an iterator to the item, we use begin() + index
			menuItems.erase(iter);
			break;//exits the loop
		}
	}
}
