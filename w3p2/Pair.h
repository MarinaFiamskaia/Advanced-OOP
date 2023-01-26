/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 6, 2022
Subject:	OOP345 NAA
Project:	Workshop 3 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include<iostream>

namespace sdds {
	class Pair{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() { return m_key; }
		const std::string& getValue() { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

		Pair() {};
		virtual std::ostream& display(std::ostream& os = std::cout)const;
		bool operator==(const Pair& toCompare)const;
	};
	std::ostream& operator<<(std::ostream& os, const Pair& toPrint);
}
#endif // !SDDS_PAIR_H