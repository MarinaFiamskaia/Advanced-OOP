/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 19, 2022
Subject:	OOP345 NAA
Project:	Final Project MS1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

//Station.cpp
#include<iostream>
#include<string>

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
		os.setf(std::ios::right);
		os.width(3);
		os.fill('0');
		os << m_id;
		os << " | ";
		os.unsetf(std::ios::right);
		os.setf(std::ios::left);
		os.width(m_widthField);
		os.fill(' ');
		os << m_name;
		os << "  | ";
		os.unsetf(std::ios::left);
		os.setf(std::ios::right);
		os.width(6);
		os.fill('0');
		os << m_serialNum;
		os << " | ";
		os.unsetf(std::ios::right);
		os.fill(' ');
		if (full) {
			os.width(4);
			os << m_stock;
			os << " | ";
			os << m_desc;
		}
		os << std::endl;
	}
}