/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		August 3, 2022
Subject:	OOP345 NAA
Project:	Final Project MS2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Utilities.h"

using std::string;

namespace sdds{
	char Utilities::m_delimiter = ' ';
	void Utilities::setFieldWidth(size_t newWidth){
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth()const{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
		std::string token{};
		std::string extracted{};
		std::string::size_type posBeg= next_pos;
		std::string::size_type posEnd= str.find(m_delimiter, posBeg);
		std::string::size_type size = posEnd - posBeg;

		extracted = str.substr(posBeg, size);
		if (extracted[0] == m_delimiter || extracted.empty()) {
			more = false;
			throw "Delimeter is found at next_pos";
		}
		if (!extracted.empty()) {
			extracted.erase(0, extracted.find_first_not_of(' '));
			extracted.erase(extracted.find_last_not_of(' ') + 1);

			token = extracted;
			next_pos = ++posEnd;
			if(next_pos == std::string::npos || next_pos == 0) {
				more = false; 
			}else {
				more = true; 
			}
			if (token.size() > m_widthField)m_widthField = token.size();
		}

		return token;
	}
	void Utilities::setDelimiter(char newDelimiter){
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter(){
		return m_delimiter;
	}
}