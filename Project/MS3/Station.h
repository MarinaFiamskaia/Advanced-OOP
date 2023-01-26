/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		August 7, 2022
Subject:	OOP345 NAA
Project:	Final Project MS3

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds {
	class Station{
		int m_id{};
		std::string m_name{};
		std::string m_desc{};
		size_t m_serialNum{};
		size_t m_stock{};

		static size_t m_widthField;
		static int id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif
