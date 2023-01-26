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
#include <fstream>
#include <string>
#include "SpellChecker.h"

using std::string;
using std::cout;
using std::endl;

namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			size_t i=0;
			do {
				string badW{};
				string goodW{};

				std::getline(file, badW, ' ');
				std::getline(file, goodW, '\n');
				if (file && !badW.empty() && !goodW.empty()) {
					badW.erase(0, badW.find_first_not_of(' '));
					badW.erase(badW.find_last_not_of(' ') + 1);

					goodW.erase(0, goodW.find_first_not_of(' '));
					goodW.erase(goodW.find_last_not_of(' ') + 1);

					sc_badWords[i] = badW;
					sc_goodWords[i] = goodW;
					sc_count[i] = 0;

					i++;
				}
			} while (file && i < MaxLength);
			file.close();
		}
	}
	void SpellChecker::operator()(std::string& text) {
		for (auto i = 0u; i < MaxLength; i++) {
			while (text.find(sc_badWords[i]) != string::npos) {
				text.replace(text.find(sc_badWords[i]), sc_badWords[i].size(), sc_goodWords[i]);
				sc_count[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const {
		out << "Spellchecker Statistics" << endl;
		for (auto i = 0u; i < MaxLength;i++) {
			out.setf(std::ios::right);
			out.width(15);
			out << sc_badWords[i];
			out << ": ";
			out << sc_count[i];
			out << " replacements";
			out << endl;
		}
	}
}