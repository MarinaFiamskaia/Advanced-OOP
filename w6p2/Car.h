/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 14, 2022
Subject:	OOP345 NAA
Project:	Workshop 6 part 2

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
		//Car(){};
		Car(std::istream& inc);
		virtual std::string condition() const;
		virtual double topSpeed() const;
		virtual void display(std::ostream& out)const;
		virtual ~Car(){};
	};
}
#endif
