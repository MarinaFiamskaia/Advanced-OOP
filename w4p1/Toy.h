/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 10, 2022
Subject:	OOP345 NAA
Project:	Workshop 4 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include<iostream>

namespace sdds {
	class Toy {
		size_t t_orderId{};
		std::string t_name{};
		size_t t_numOfItems{};
		double t_price{};
		const double t_hst{0.13}; //??
	public:
		Toy() {};
		void update(int numItems);
		Toy(const std::string& toy);
		friend std::ostream& operator<<(std::ostream& os, const Toy toy);
	};
}
#endif // !SDDS_TOY_H