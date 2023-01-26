/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 14, 2022
Subject:	OOP345 NAA
Project:	Workshop 6 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <sstream>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in) {
		Vehicle* ptr = nullptr;

		std::string temp;
		getline(in, temp);

		temp.erase(0, temp.find_first_not_of(' '));
		std::stringstream line(temp);

		if (!temp.empty() && temp.size()>1) {
			if (temp[0] == 'C' || temp[0] == 'c'){
				ptr = new Car(line);
			}
			else if (temp[0] == 'R' || temp[0] == 'r') {
				ptr = new Racecar(line);
			}
			else {
				std::string msg = "Unrecognized record type: [";
				msg += temp[0];
				msg += "]";
				throw msg;
			}
		}
		return ptr;
	}
}