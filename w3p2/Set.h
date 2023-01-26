/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 6, 2022
Subject:	OOP345 NAA
Project:	Workshop 3 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_SET_H
#define SDDS_SET_H

#include<iostream>
#include<cmath>
#include"Collection.h"

namespace sdds {
	template<typename T>
	class Set :public Collection<T, 100> {
	public:
		bool add(const T& item) {
			bool done{};
			size_t itemExist{};
			for (size_t i = 0; i < this->size(); i++) {
				if (this->operator[](i) == item)itemExist++;
			}
			if (!itemExist){
				done=Collection<T, 100>::add(item);
			}
			return done;
		}
	};

	template<>
	bool Set<double>::add(const double& item){
		bool done{};
		size_t itemExist{};
		double diff{};

		for (size_t i = 0; i < this->size(); i++) {
			diff = std::fabs(item - this->operator[](i));
			if (diff <= 0.01) {
				itemExist++;
			}
		}
		if (!itemExist) {
			done=Collection<double, 100>::add(item);
		}
		return done;
	}
}
#endif // !SDDS_SET_H
