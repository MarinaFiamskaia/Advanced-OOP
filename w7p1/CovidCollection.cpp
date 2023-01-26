/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 18, 2022
Subject:	OOP345 NAA
Project:	Workshop 7 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "CovidCollection.h"

namespace sdds {
	Covid::Covid(std::string input) {
		std::string country{};
		std::string city{};
		std::string variant{};
		std::string numOfCases{};
		std::string year{};
		std::string numOfDeaths{};
		std::string wrkStr{};

		wrkStr = input;
			
		country = wrkStr.substr(0, 25);
		wrkStr.erase(0, 25);
		city = wrkStr.substr(0, 25);
		wrkStr.erase(0, 25);
		variant = wrkStr.substr(0, 25);
		wrkStr.erase(0, 25);
		year = wrkStr.substr(0, 5);
		wrkStr.erase(0, 5);
		numOfCases = wrkStr.substr(0, 5);
		wrkStr.erase(0, 5);
		numOfDeaths = wrkStr.substr(0, 5);
			
		country.erase(0, country.find_first_not_of(' '));
		country.erase(country.find_last_not_of(' ') + 1);

		city.erase(0, city.find_first_not_of(' '));
		city.erase(city.find_last_not_of(' ') + 1);

		variant.erase(0, variant.find_first_not_of(' '));
		variant.erase(variant.find_last_not_of(' ') + 1);

		m_country = country;
		m_city = city;
		m_variant = variant;
		m_year = std::stoi(year);
		m_numOfCases = std::stoi(numOfCases);
		m_numOfDeaths = std::stoi(numOfDeaths);
	}
	CovidCollection::CovidCollection(const std::string filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			while (!file.eof()) {
				std::string covidStr{};
				getline(file, covidStr);
				if (!covidStr.empty()) {
					Covid covid(covidStr);
					m_covid.push_back(covid);
				}
			}
		}
	}
	void CovidCollection::display(std::ostream& out) const {
		std::for_each(m_covid.begin(), m_covid.end(), [&out](const Covid
			& theCovid) {
				out << theCovid << std::endl;
			});
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		out << "| ";
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out.width(21);
		out << theCovid.m_country;
		out << " | ";
		out.width(15);
		out << theCovid.m_city;
		out << " | ";
		out.width(20);
		out << theCovid.m_variant;
		out << " | ";
		out.unsetf(std::ios::left);
		out.setf(std::ios::right);
		out.width(6);
		if (theCovid.m_year > 0) {
			out << theCovid.m_year;
		}
		else {
			out << " ";
		}
		out << " | ";
		out.width(4);
		out << theCovid.m_numOfCases;
		out << " | ";
		out.width(3);
		out << theCovid.m_numOfDeaths;
		out << " |";
		out.unsetf(std::ios::right);
		return out;
	}
}