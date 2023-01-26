/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 14, 2022
Subject:	OOP345 NAA
Project:	Workshop 6 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds {
	class Racecar : public Car {
		double m_booster{};

	public:
		Racecar(std::istream& in);
		virtual void display(std::ostream& out)const;
		virtual double topSpeed() const;
		virtual ~Racecar() {};
	};
}
#endif
