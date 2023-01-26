/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 20, 2022
Subject:	OOP345 NAA
Project:	Workshop 5 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace sdds {
	class Movie {
		std::string m_title{};
		size_t m_year{};
		std::string m_desc{};
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_desc);
		}
	};
}
#endif // !SDDS_MOVIE_H
