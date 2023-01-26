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

#include <iostream>
#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in){
		std::string booster; 
		std::getline(in, booster, '\n');
		m_booster = std::stod(booster);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}