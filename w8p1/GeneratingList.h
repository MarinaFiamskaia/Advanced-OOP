/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 25, 2022
Subject:	OOP345 NAA
Project:	Workshop 8 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
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
		//mod 10 formula
		//check digit is the last one on the right
		//check digit is calc 10-(s mod 10)
		//ex. string 7992739871
		//start from 1 (right) move left to 7
		//multiply by 1 every 1st, 3rd, 5th, etc
		//multiply by 2 every 2nd, 4th, 6th etc
		//ex. 7*1  9*2  9*1  2*2  7*2  3*1  9*2  8*1  7*2  1*1
		//ex. 7 18 9 4 7 6 9 16 7 2
		//sum num values
		//ex. 7 + 8+1 + 9 + 4 + 7 + 6 + 9 + 1+6 + 7 + 2 =67
		//to get check digit= 10-(67 mod 10)=3
		//the payload should be 79927398713<<<<<<<
		//to validate drop the check digit in calculations
		// mod 10 -> always will give you the last digit on the right
		//bool lunhsAlgorithm(const std::string& sin) {
		//	int nDigits = sin.length();
		//	int sum = std::stoi(sin[nDigits - 1]);
		//	int parity = (nDigits - 2) % 2;
		//	for (auto i = 0; i < nDigits - 2; i++) {
		//		int digit = std::stoi(sin[i]);
		//		if (i % 2 == parity)digit = digit * 2;
		//		if (digit > 9)digit = digit - 9;
		//		sum = sum + digit;
		//	}
		//	return (sum % 10) == 0;
		//}
		bool checkLuhn(const std::string& cardNo){
			int nDigits = cardNo.length();

			int nSum = 0, isSecond = false;
			for (int i = nDigits - 1; i >= 0; i--) {

				int d = cardNo[i] - '0';

				if (isSecond == true)
					d = d * 2;

				// We add two digits to handle
				// cases that make two digits after
				// doubling
				nSum += d / 10;
				nSum += d % 10;

				isSecond = !isSecond;
			}
			return (nSum % 10 == 0);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T& in){
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
