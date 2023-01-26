/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 20, 2022
Subject:	OOP345 NAA
Project:	Workshop 5 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Book.h"

using std::string;
using std::cout;
using std::endl;

namespace sdds{
	const string& Book::title() const {
		return b_title;
	}
	const string& Book::country() const {
		return b_pubCountry;
	}
	const size_t& Book::year() const {
		return b_year;
	}
	double& Book::price() {
		return b_price;
	}
	Book::Book(const string& strBook) {
		string author{};
		string title{};
		string country{};
		string price{};
		string year{};
		string description{};
		string wrkStr{};

		if (!strBook.empty()) {
			wrkStr = strBook;

			author = wrkStr.substr(0, wrkStr.find(','));//wrkStr 
			wrkStr.erase(0, wrkStr.find(',') + 1);

			title = wrkStr.substr(0, wrkStr.find(','));
			wrkStr.erase(0, wrkStr.find(',') + 1);

			country = wrkStr.substr(0, wrkStr.find(','));
			wrkStr.erase(0, wrkStr.find(',') + 1);

			price = wrkStr.substr(0, wrkStr.find(','));
			wrkStr.erase(0, wrkStr.find(',') + 1);

			year = wrkStr.substr(0, wrkStr.find(','));
			wrkStr.erase(0, wrkStr.find(',') + 1);

			description = wrkStr.substr(0, wrkStr.find('\n'));

			author.erase(0, author.find_first_not_of(' '));
			author.erase(author.find_last_not_of(' ') + 1);

			title.erase(0, title.find_first_not_of(' '));
			title.erase(title.find_last_not_of(' ') + 1);

			country.erase(0, country.find_first_not_of(' '));
			country.erase(country.find_last_not_of(' ') + 1);

			description.erase(0, description.find_first_not_of(' '));
			description.erase(description.find_last_not_of(' ') + 1);
			
			b_author = author;
			b_title = title;
			b_pubCountry = country;
			b_price = std::stod(price);
			b_year = std::stoi(year);
			b_desc = description;
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const Book& book) {
		ostr.width(20);
		ostr << book.b_author;
		ostr << " | ";
		ostr.width(22);
		ostr << book.b_title;
		ostr << " | ";
		ostr.width(5);
		ostr << book.b_pubCountry;
		ostr << " | ";
		ostr.width(4);
		ostr << book.b_year;
		ostr << " | ";
		ostr.setf(std::ios::fixed);
		ostr.precision(2);
		ostr.width(6);
		ostr << book.b_price;
		ostr << " | ";
		ostr << book.b_desc;
		ostr << endl;
		return ostr;
	}
}