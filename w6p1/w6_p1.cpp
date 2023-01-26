/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 10, 2022
Subject:	OOP345 NAA
Project:	Workshop 6 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Utilities.h"
#include "Utilities.h"
#include "Autoshop.h"
#include "Autoshop.h"


void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
		sdds::Vehicle* aVehicle = sdds::createInstance(file);
		if (aVehicle)
			as += aVehicle;
	}
}

// ws cars.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as;
	loadData(argv[1], as);
	as.display(std::cout);

	return 0;
}
