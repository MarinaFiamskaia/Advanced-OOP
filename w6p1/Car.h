/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 10, 2022
Subject:	OOP345 NAA
Project:	Workshop 6 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds{
	class Car : public Vehicle {
		std::string m_maker{};
		std::string m_condition{};
		double m_tSpeed{};

	public:
		Car(){};
		Car(std::istream& inc);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		virtual ~Car(){};
	};
}
#endif
