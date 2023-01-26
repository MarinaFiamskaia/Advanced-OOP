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
#include "Movie.h"

using std::string;
using std::cout;
using std::endl;

namespace sdds {
	const std::string& Movie::title() const {
		return m_title;
	}
	Movie::Movie(const std::string& strMovie) {
		string title{};
		string year{};
		string desc{};

		if (!strMovie.empty()) {
			string wrkStr = strMovie;

			title = wrkStr.substr(0, wrkStr.find(','));
			wrkStr.erase(0, wrkStr.find(',') + 1);

			year = wrkStr.substr(0, wrkStr.find(','));
			wrkStr.erase(0, wrkStr.find(',') + 1);

			desc = wrkStr.substr(0, wrkStr.find('\n'));

			title.erase(0, title.find_first_not_of(' '));
			title.erase(title.find_last_not_of(' ') + 1);

			desc.erase(0, desc.find_first_not_of(' '));
			desc.erase(desc.find_last_not_of(' ') + 1);

			m_title = title;
			m_year = std::stoi(year);
			m_desc = desc;
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const Movie& movie) {
		ostr.width(40);
		ostr << movie.m_title;
		ostr << " | ";
		ostr.width(4);
		ostr << movie.m_year;
		ostr << " | ";
		ostr << movie.m_desc;
		ostr << endl;
		return ostr;
	}
}