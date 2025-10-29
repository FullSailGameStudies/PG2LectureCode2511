#include "FullSailCourse.h"

//a DEFINITION
void FullSailCourse::GetGrades(std::vector<float>& courseGrades) const
{
	//cannot modify fields of the class
	//name_ = "PG2";

	//cannot call NON-const methods of the class
	//SetName("PG2 2511");

	int numberOfGrades = 20;
	for (int i = 0; i < numberOfGrades; i++)
	{
		//rand() generates a random # from 0-32767
		// % returns the remainder
		// % 10001 returns a value from 0-10000
		courseGrades.push_back(rand() % 10001 / 100.0);
	}
}