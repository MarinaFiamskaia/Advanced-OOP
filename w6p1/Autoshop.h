/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 10, 2022
Subject:	OOP345 NAA
Project:	Workshop 6 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out);
		virtual ~Autoshop();
	};
}
#endif
