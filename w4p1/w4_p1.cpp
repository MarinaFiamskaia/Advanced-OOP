/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 10, 2022
Subject:	OOP345 NAA
Project:	Workshop 4 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
// Workshop 4 - Containers
// 2020/01/28 - Cornel
// 2021/01/19 - Chris
// 2021/10/01 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Toy.h"


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n";

	sdds::Toy** ppToys = nullptr; //dynamic array of pointers to the pointer of object instance
	size_t cnt = 0;

	// Process the file
	if (argc > 1) {
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string strToy;
		// count how many records are in the file
		do //did in ws2
		{
			std::getline(file, strToy);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strToy[0] != '#')
					++cnt;
			}
		} while (file);

		ppToys = new sdds::Toy * [cnt]; //how is **ptr is actually initialized
		//allocating a new array of Toy *ptr
		//dynamic ptr array of Toy*ptr
		//needed for part 2
		cnt = 0;

		// read again from the file, but this time load and store data
		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			std::getline(file, strToy);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strToy[0] != '#')
				{
					ppToys[cnt] = new sdds::Toy(strToy);//dynamic ptr[index] to the Toy string
					++cnt;
				}
			}
		} while (file);
		file.close();
	}
	std::cout << "\nToys\n--------------------------\n";
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cout << *ppToys[i];
	}
	std::cout << "--------------------------\n\n";

	// modify the amount for some toys
	if (cnt > 2)
	{
		ppToys[0]->update(6);
		ppToys[2]->update(4);
	}

	std::cout << "\nUpdated Toys\n--------------------------\n";
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cout << *ppToys[i];
	}
	std::cout << "--------------------------\n\n";

	// cleanup //KEY INFO VERY IMPORTANT
	//two layers of deallocation
	//needed for part 2
	for (auto i = 0u; i < cnt; ++i)
		delete ppToys[i];
	delete[] ppToys;

	return 0;
}

