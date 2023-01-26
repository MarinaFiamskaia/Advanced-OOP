/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 18, 2022
Subject:	OOP345 NAA
Project:	Workshop 7 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "CovidCollection.h"
#include "CovidCollection.h"


void printbar(std::ostream& out = std::cout)
{
	out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
}

void printHeader(const char* title, std::ostream& out = std::cout)
{
	printbar(out);
	out << "| " << std::left << std::setw(85) << title << std::right << "|\n";
	printbar(out);
}

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::CovidCollection theCollection(argv[1]);

	printHeader("The original collection");
	theCollection.display(std::cout);
	printbar();
}