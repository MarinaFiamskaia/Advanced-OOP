/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 4, 2022
Subject:	OOP345 NAA
Project:	Workshop 3 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

//#include<iostream>
#include"Pair.h"

namespace sdds {
	template<typename T, size_t CAPACITY=0>
	class Collection{
		T c_object[CAPACITY]{};
		size_t c_noOfArrayObjects{};
		static T c_dummy;
	public:
		size_t size()const { return c_noOfArrayObjects; }
		void display(std::ostream& os = std::cout)const {
			os << "----------------------" << std::endl;
			os << "| Collection Content |" << std::endl;
			os << "----------------------" << std::endl;
			for (size_t i = 0; i < c_noOfArrayObjects; i++) {
				os << c_object[i] << std::endl;
			}
			os << "----------------------" << std::endl;
		}
		bool add(const T& item) {
			bool done = false;
			if (c_noOfArrayObjects < CAPACITY) {
				c_object[c_noOfArrayObjects] = item;
				c_noOfArrayObjects++;
				done = true;
			}
			return done;
		}
		T& operator[](size_t index) {
			return index < c_noOfArrayObjects&& index >= 0 ? c_object[index] : c_dummy;
		}

	};
	template<typename T, size_t CAPACITY>
	T Collection <T, CAPACITY>::c_dummy{};

	template<>
	Pair Collection<Pair, 100>::c_dummy("No Key", "No Value");
}


#endif // !SDDS_COLLECTION_H