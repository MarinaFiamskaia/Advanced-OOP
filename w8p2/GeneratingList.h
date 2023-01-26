/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 26, 2022
Subject:	OOP345 NAA
Project:	Workshop 8 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//bool checkLuhn() is taken from https: //www.geeksforgeeks.org/luhn-algorithm****
*/

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {
		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool checkLuhn(const std::string& sin) { //taken from https: //www.geeksforgeeks.org/luhn-algorithm/
			int nDigits = sin.length();

			int nSum = 0, isSecond = false;
			for (int i = nDigits - 1; i >= 0; i--) {

				int d = sin[i] - '0';

				if (isSecond == true)
					d = d * 2;

				nSum += d / 10;
				nSum += d % 10;

				isSecond = !isSecond;
			}
			return (nSum % 10 == 0);
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(const  std::unique_ptr<T> in){
			list.push_back(*in);
		}
		

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T& in) {
			list.push_back(in);
		}
		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
