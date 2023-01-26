/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		August 7, 2022
Subject:	OOP345 NAA
Project:	Final Project MS3

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string>

#include "Utilities.h"
#include "Station.h"

namespace sdds {
	size_t Station::m_widthField=0;
	int Station::id_generator = 0;

	Station::Station(const std::string& str) {
		size_t next_pos{};
		bool more{true};
		Utilities utility;

		m_id = ++id_generator;

		try{
			m_name = more ? utility.extractToken(str, next_pos, more): "";
			m_serialNum = more ? std::stoi(utility.extractToken(str, next_pos, more)): 0;
			m_stock = more ? std::stoi(utility.extractToken(str, next_pos, more)): 0;
			m_widthField = std::max(utility.getFieldWidth(), m_widthField);
			m_desc = utility.extractToken(str, next_pos, more);
		}
		catch (std::string& msg){
			std::cout << msg;
		}
	}
	const std::string& Station::getItemName() const {
		return m_name;
	}
	size_t Station::getNextSerialNumber() {
		return m_serialNum++;
	}
	size_t Station::getQuantity() const {
		return m_stock;
	}
	void Station::updateQuantity() {
		if(m_stock > 0)m_stock--;
	}
	void Station::display(std::ostream& os, bool full) const {
		if (!m_name.empty()){
			os << std::right
				<< std::setfill('0')
				<< std::setw(3)
				<< m_id;
			os << " | ";
			os << std::left
				<< std::setfill(' ')
				<< std::setw(m_widthField)
				<< m_name;
			os << "  | ";
			os << std::right
				<< std::setfill('0')
				<< std::setw(6)
				<< m_serialNum;
			os << " | ";

			if (full) {
				os << std::right
					<< std::setfill(' ')
					<< std::setw(4)
					<< m_stock;
				os << " | ";
				os << m_desc;
			}
			os << std::endl;
		}
	}
}