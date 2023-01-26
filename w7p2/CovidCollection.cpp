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
#include <numeric>
#include <vector>
#include <list>
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
		m_deaths = std::stoi(numOfDeaths);
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
		size_t totalCases{};
		size_t totalDeaths{};
		if (std::all_of(m_covid.begin(), m_covid.end(), [&out](const Covid
			& theCovid) {
				out << theCovid << std::endl;
				return true;
			})) {
			totalCases = std::accumulate(m_covid.begin(), m_covid.end(), 0, [](const size_t& currentCases, const Covid& theCovid) {
				return currentCases + theCovid.m_numOfCases;
				});
			totalDeaths = std::accumulate(m_covid.begin(), m_covid.end(), 0, [](const size_t& currentDeaths, const Covid& theCovid) {
				return currentDeaths + theCovid.m_deaths;
				});
		};
		
		out.fill('-');
		out.width(88);
		out << "-";
		out << std::endl;
		out.setf(std::ios::right);
		out << "| ";
		out.fill(' ');
		out.width(78);
		out << "Total Cases Around the World: ";
		out.width(6);
		out << totalCases;
		out << " |";
		out << std::endl;
		out << "| ";
		out.width(78);
		out << "Total Deaths Around the World: ";
		out.width(6);
		out << totalDeaths;
		out << " |";
		out << std::endl;
		out.unsetf(std::ios::right);
	}
	void CovidCollection::sort(std::string sortByField) {
		if (sortByField == "country") {
			std::sort(m_covid.begin(), m_covid.end(), [](const Covid& a, const Covid& b) {
				return a.m_country < b.m_country;
				});
		}
		else if (sortByField == "variant") {
			std::sort(m_covid.begin(), m_covid.end(), [](const Covid& a, const Covid& b) {
				return a.m_variant < b.m_variant;
				});
		}
		else if (sortByField == "cases") {
			std::sort(m_covid.begin(), m_covid.end(), [](const Covid& a, const Covid& b) {
				return a.m_numOfCases < b.m_numOfCases;
				});
		}
		else if (sortByField == "deaths") {
			std::sort(m_covid.begin(), m_covid.end(), [](const Covid& a, const Covid& b) {
				return a.m_deaths < b.m_deaths;
				});
		}
	}
	void CovidCollection::cleanList() {
		auto replace = [](Covid& theCovid) {
			if (theCovid.m_variant == "[None]")
				theCovid.m_variant.clear();
			return theCovid;
		};
		std::transform(m_covid.begin(), m_covid.end(), m_covid.begin(), replace);
	}
	bool CovidCollection::inCollection(std::string variant) const {
		return  any_of(m_covid.begin(), m_covid.end(), [=](Covid theCovid){
			return theCovid.m_variant == variant;
			});
	}
	std::list<Covid> CovidCollection::getListForCountry(std::string country) const {
		std::list<Covid> listForCountry;
		std::copy_if(m_covid.begin(), m_covid.end(), back_inserter(listForCountry), [=](const Covid& theCovid){
			return theCovid.m_country == country; });
		return listForCountry;
	}
	std::list<Covid> CovidCollection::getListForVariant(std::string variant) const {
		/*std::list<Covid>listVariant;
		std::for_each(m_covid.begin(), m_covid.end(), [=](const Covid& theCovid) {
			if(theCovid.m_variant == variant)listVariant.push_back(theCovid); 
			});*/

		std::list<Covid>listVariant;
		std::copy_if(m_covid.begin(), m_covid.end(), back_inserter(listVariant), [=](const Covid& theCovid) {
			return theCovid.m_variant == variant; });

		return listVariant;
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
		out << theCovid.m_deaths;
		out << " |";
		out.unsetf(std::ios::right);
		return out;
	}
}