/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		May 21, 2022
Subject:	OOP345 NAA
Project:	Workshop 1 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
	class FoodOrder {
		char fo_name[10]{};
		char* fo_foodDesc{};
		double fo_price{};
		bool fo_dailySpecial{};

		void set(const char* name, const char* foodDesc, double price, bool dailySpecial);
		void setEmpty();

	public:
		FoodOrder(){};
		FoodOrder(const FoodOrder& cnt);
		FoodOrder& operator=(const FoodOrder& cnt);
		~FoodOrder();
		void read(std::istream& istr);
		void display()const;
	};
}

#endif // !SDDS_FOODORDER_H
