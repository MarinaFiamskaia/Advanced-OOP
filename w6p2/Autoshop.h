/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 14, 2022
Subject:	OOP345 NAA
Project:	Workshop 6 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;

	public:
		Autoshop() {};
		Autoshop(const Autoshop& shop)=delete;
		Autoshop(Autoshop&& shop)noexcept = delete;
		Autoshop& operator=(const Autoshop& shop) = delete;
		Autoshop& operator=(Autoshop&& shop) = delete;

		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out);
		virtual ~Autoshop();

		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			std::vector<Vehicle*>::iterator iter;
			for (iter = m_vehicles.begin(); iter != m_vehicles.end(); iter++) {
				if (test(*iter)) {
					vehicles.push_back(*iter);
				}
			}
		}
	};
}
#endif
