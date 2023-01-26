/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		May 20, 2022
Subject:	OOP345 NAA
Project:	Workshop 1 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "foodorder.h"

double g_taxrate = 0.00;
double g_dailydiscount = 0.00;

namespace sdds {
	void FoodOrder::set(const char* name, const char* foodDesc, double price, bool dailySpecial) {
		strcpy(fo_name, name);
		strcpy(fo_foodDesc, foodDesc);
		fo_price = price;
		fo_dailySpecial = dailySpecial;
	}
	void FoodOrder::setEmpty(){
		fo_name[0] = '0';
		fo_foodDesc[0] = '0';
		fo_price = 0.00;
		fo_dailySpecial = false;
	}
	void FoodOrder::read(std::istream& istr){
		char name[10]{};
		char foodDesc[25]{};
		double price{};
		char dailySpecialchar{};
		bool dailySpecial{};

		if (istr) {
		//	static int read{ 1 };

		//	std::cout << "reading: " << read++ << std::endl;
			istr.getline(name, 10, ',');
			istr.getline(foodDesc, 25, ',');
			istr >> price;
			istr.ignore(1);
			istr.get(dailySpecialchar);

			if (istr && name[0]!='0') {
				if (dailySpecialchar == 'Y')dailySpecial = true;
				set(name, foodDesc, price, dailySpecial);
			}
			else {
				setEmpty();
			}
		}
	}
	void FoodOrder::display()const{
		static int counter{ 1 };
		double priceWithTax{};

		std::cout.setf(std::ios::left);
		std::cout.width(2);
		std::cout << counter++;
		std::cout << ". ";

		if (this->fo_name[0] != '0') {
			std::cout.width(10);
			std::cout << fo_name;
			std::cout << "|";
			std::cout.width(25);
			std::cout << fo_foodDesc;
			std::cout << "|";

			priceWithTax = fo_price * (1 + g_taxrate);
			std::cout.width(12);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			std::cout << priceWithTax;
			std::cout << "|";
			std::cout.unsetf(std::ios::left);
			std::cout.setf(std::ios::right);
			std::cout.width(13);
			if (fo_dailySpecial) {
				std::cout << priceWithTax - g_dailydiscount;
			}
			std::cout << std::endl;
			std::cout.unsetf(std::ios::right);
		}
		else {
			std::cout << "No Order" << std::endl;
		}
	}
}