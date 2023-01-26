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

#include <iostream>
#include <string>
#include "Car.h"

namespace sdds {
	Car::Car(std::istream& inc) {
		std::string tag{};
		std::string maker{};
		std::string condition{};
		std::string speed{};

		std::getline(inc, tag, ',');
		std::getline(inc, maker, ',');
		std::getline(inc, condition, ',');
		std::getline(inc, speed, '\n');

		maker.erase(0, maker.find_first_not_of(' '));
		maker.erase(maker.find_last_not_of(' ') + 1);

		condition.erase(0, condition.find_first_not_of(' '));
		condition.erase(condition.find_last_not_of(' ') + 1);
		
		//if (inc.fail()) {
		//	inc.clear();
		//	throw std::string("Invalid record!");
		//}
		//else {
			m_maker = maker;
			m_condition = condition;
			m_tSpeed = std::stod(speed);
		//}
	}

	std::string Car::condition() const {
		std::string condition{};
		if (m_condition == "n")condition = "new";
		else if (m_condition == "u")condition = "used";
		else if (m_condition == "b")condition = "broken";
				
		return condition;
	}

	double Car::topSpeed() const {
		return m_tSpeed;
	}

	void Car::display(std::ostream& out) const {
		out << "| ";
		out.setf(std::ios::right);
		out.width(10);
		out << m_maker;
		out << " | ";
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out.width(6);
		out << condition();
		out << " | ";
		out.setf(std::ios::fixed);
		out.precision(2);
		out.width(6);
		out << topSpeed();
		out << " |";
	}
}