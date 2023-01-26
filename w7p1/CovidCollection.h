/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 18, 2022
Subject:	OOP345 NAA
Project:	Workshop 7 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H

#include <iostream>
#include <vector>

namespace sdds {
	struct Covid {
		std::string m_country{};
		std::string m_city{};
		std::string m_variant{};
		int m_numOfCases{};
		int m_year{};
		int m_numOfDeaths{};

		Covid(std::string input);
	};

	class CovidCollection{
		std::vector<Covid> m_covid;
	public:
		CovidCollection(const std::string filename);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif
