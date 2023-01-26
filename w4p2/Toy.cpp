/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 12, 2022
Subject:	OOP345 NAA
Project:	Workshop 4 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
	void Toy::update(int numItems) {
		t_numOfItems = numItems;
	}
	Toy::Toy(const std::string& toy) {
		std::string orderID{};
		std::string name{};
		std::string numOfItems{};
		std::string price{};

		if (!toy.empty()) {
			std::string workingStr = toy;

			orderID = workingStr.substr(0, workingStr.find(':'));
			workingStr.erase(0, workingStr.find(':')+1);

			name= workingStr.substr(0, workingStr.find(':'));
			workingStr.erase(0, workingStr.find(':')+1);

			numOfItems= workingStr.substr(0, workingStr.find(':'));
			workingStr.erase(0, workingStr.find(':')+1);

			price= workingStr.substr(0, workingStr.find('\n'));

			name.erase(0, name.find_first_not_of(' '));
			name.erase(name.find_last_not_of(' ') + 1);

			t_orderId = std::stoi(orderID);
			t_name = name;
			t_numOfItems = std::stoi(numOfItems);
			t_price = std::stod(price);
		}	
	}
	std::ostream& operator<<(std::ostream& ostr, const Toy& toy) {
		double subTotal = (double)toy.t_numOfItems * toy.t_price;
		double tax = subTotal * toy.t_hst;
		double total = subTotal + tax;

		ostr << "Toy";
		ostr.width(8);
		ostr << toy.t_orderId;
		ostr << ": ";
		ostr.setf(std::ios::right);
		ostr.width(17);
		ostr << toy.t_name;
		ostr.width(3);
		ostr << toy.t_numOfItems;
		ostr << " items";
		ostr.width(8);
		ostr << toy.t_price;
		ostr << "/item  subtotal:";
		ostr.setf(std::ios::fixed);
		ostr.precision(2);
		ostr.width(7);
		ostr << subTotal;
		ostr << " tax:";
		ostr.width(6);
		ostr << tax;
		ostr << " total:";
		ostr.width(7);
		ostr << total;
		ostr << std::endl;

		return ostr;
	}
}