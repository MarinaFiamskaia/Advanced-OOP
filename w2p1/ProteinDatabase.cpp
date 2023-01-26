/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		May 30, 2022
Subject:	OOP345 NAA
Project:	Workshop 2 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include "ProteinDatabase.h"

namespace sdds {
	ProteinDatabase::ProteinDatabase(const char* file) {
		size_t numberOfProteinSequence{};
		std::string proteinStr{};
		size_t i{};
			 
		std::ifstream fin(file);
		while (fin) {
			char x = fin.get();
			if (x == '>')
				numberOfProteinSequence++;
		}

		fin.clear();
		fin.seekg(0);

		delete[] pd_str;
		pd_str = nullptr;
		pd_str = new std::string[numberOfProteinSequence];
		pd_noOfSequences = numberOfProteinSequence;

		while (fin && i<pd_noOfSequences) {
			getline(fin, proteinStr);
			if (proteinStr[0] != '>') {
				pd_str[i] += proteinStr;
			}
			if (proteinStr[0] == '>' && !pd_str[i].empty()) {
				i++;
			}
		}
		fin.close();
	}
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& toCopy) {
		*this=toCopy;
	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& toCopy) {
		size_t i;
		if (this != &toCopy) {
			delete[] pd_str;
			pd_str = nullptr;
			if (toCopy.pd_str) {
				this->pd_str = new std::string[toCopy.pd_noOfSequences];
				for (i = 0; i < toCopy.pd_noOfSequences; i++) {
					this->pd_str[i] = toCopy.pd_str[i];
				}
				this->pd_noOfSequences = toCopy.pd_noOfSequences;
			}
		}
		return *this;
	}
	ProteinDatabase::~ProteinDatabase() {
		delete[] pd_str;
		pd_str = nullptr;
	}
	size_t ProteinDatabase::size()const {
		return pd_noOfSequences;
	}
	std::string ProteinDatabase::operator[](size_t index)const {
		std::string stringToReturn = " ";
		if (index < pd_noOfSequences) {
			stringToReturn = pd_str[index];
		}
		return stringToReturn;
	}
}