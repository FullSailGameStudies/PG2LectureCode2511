#pragma once
#include <vector>
#include <string>
class Menu
{
public:
	//a method DECLARATION:
	//  return type
	//  name
	//  parameter list

	//ends with a ;
	//no {  }

	//AddMenuItem - add 1 item to the vector
	void AddMenuItem(std::string itemToAdd);
	void ShowMenu();

	void RemoveItem(std::string itemToRemove);

private:
	std::vector<std::string> menuItems;
};

