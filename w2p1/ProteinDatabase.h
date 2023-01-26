/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		May 30, 2022
Subject:	OOP345 NAA
Project:	Workshop 2 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/

#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H
#include <iostream>

namespace sdds {
	class ProteinDatabase {
		std::string* pd_str{};
		size_t pd_noOfSequences{};
	public:
		ProteinDatabase() {};
		ProteinDatabase(const char* file);
		ProteinDatabase(const ProteinDatabase& toCopy);
		ProteinDatabase& operator=(const ProteinDatabase& toCopy);
		virtual~ProteinDatabase();
		size_t size()const;
		std::string operator[](size_t index)const;
	};
}
#endif // !SDDS_PROTEINDATABASE_H
