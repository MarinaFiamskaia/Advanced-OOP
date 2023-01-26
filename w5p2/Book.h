/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 19, 2022
Subject:	OOP345 NAA
Project:	Workshop 5 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds {
	class Book {
		std::string b_author{};
		std::string b_title{};
		std::string b_pubCountry{};
		size_t b_year{};
		double b_price{};
		std::string b_desc{};
	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
		template <typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(b_desc);
		}
	};
}
#endif // !SDDS_BOOK_H
