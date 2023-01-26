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

#include "Autoshop.h"
#include "Vehicle.h"
#include "Car.h"

namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) {
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";

		std::vector<Vehicle*>::iterator iter;
		for (iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++) {
			(*iter)->display(out);
			out << std::endl;
		}
		out << "--------------------------------\n";
	}

	Autoshop::~Autoshop() {
		std::vector<Vehicle*>::iterator iter;
		for (iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++) {
			delete* iter;
		}
	}
}