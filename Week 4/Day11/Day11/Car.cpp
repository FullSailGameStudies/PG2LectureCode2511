#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::DeserializeCSV(const std::string& csvData, char delim)
{
	//parse the csvData string for the fields
	std::stringstream csvStream(csvData);
	std::string data;
	std::getline(csvStream, data, delim);
	mModelYear = std::stoi(data);
	std::getline(csvStream, mMake, delim);
	std::getline(csvStream, mModel, delim);
}

void Car::SerializeCSV(std::ostream& outFile, char delimiter) const
{
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}
