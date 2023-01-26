/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 20, 2022
Subject:	OOP345 NAA
Project:	Workshop 5 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>

namespace sdds {
	const int MaxLength = 6; 

	class SpellChecker {
		std::string sc_badWords[MaxLength]{};
		std::string sc_goodWords[MaxLength]{};
		size_t sc_count[MaxLength]{};
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif // !SDDS_SPELLCHECKER_H