/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		August 3, 2022
Subject:	OOP345 NAA
Project:	Final Project MS2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

namespace sdds {
	class Utilities {
		size_t m_widthField{ 1 };
		static char m_delimiter;
	public:
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
}
#endif
