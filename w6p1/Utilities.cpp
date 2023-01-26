/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 10, 2022
Subject:	OOP345 NAA
Project:	Workshop 6 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <sstream>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* ptr = nullptr;

		std::string temp;
		getline(in, temp);

		temp.erase(0, temp.find_first_not_of(' '));
		std::stringstream line(temp);

		if (!temp.empty()) {
			if (temp[0] == 'C' || temp[0] == 'c'){
				ptr = new Car(line);
			}
			//else if (toupper(temp[0]) == 'R') {
			//	//ptr = new Racecar(line);
			//}
		}
		return ptr;
	}
}