/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 6, 2022
Subject:	OOP345 NAA
Project:	Workshop 3 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include"Pair.h"

namespace sdds {
	std::ostream& Pair::display(std::ostream& os)const {
		os.setf(std::ios::right);
		os.width(20);
		os << m_key;
		os.unsetf(std::ios::right);
		os.setf(std::ios::left);
		os << ": " << m_value;
		return os;
	}
	bool Pair::operator==(const Pair& toCompare)const {
		return m_key == toCompare.m_key;
	}
	std::ostream& operator<<(std::ostream& os, const Pair& toPrint) {
		return toPrint.display(os);
	}
}