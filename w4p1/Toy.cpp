/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 10, 2022
Subject:	OOP345 NAA
Project:	Workshop 4 part 1

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

			//orderID.erase(0, orderID.find_first_not_of(' '));
			//orderID.erase(orderID.find_last_not_of(' ')+1);

			name.erase(0, name.find_first_not_of(' '));
			name.erase(name.find_last_not_of(' ') + 1);

			//numOfItems.erase(0, numOfItems.find_first_not_of(' '));
			//numOfItems.erase(numOfItems.find_last_not_of(' ') + 1);

			//price.erase(0, price.find_first_not_of(' '));
			//price.erase(price.find_last_not_of(' ') + 1);

			t_orderId = std::stoi(orderID);
			t_name = name;
			t_numOfItems = std::stoi(numOfItems);
			t_price = std::stod(price);
		}	
	}
	std::ostream& operator<<(std::ostream& os, const Toy toy) {
		double subTotal = (double)toy.t_numOfItems * toy.t_price;
		double tax = subTotal * toy.t_hst;
		double total = subTotal + tax;

		os << "Toy";
		os.width(8);
		os << toy.t_orderId;
		os << ": ";
		os.setf(std::ios::right);
		os.width(17);
		os << toy.t_name;
		os.width(3);
		os << toy.t_numOfItems;
		os << " items";
		os.width(8);
		os << toy.t_price;
		os << "/item  subtotal:";
		os.setf(std::ios::fixed);
		os.precision(2);
		os.width(7);
		os << subTotal;
		os << " tax:";
		os.width(6);
		os << tax;
		os << " total:";
		os.width(7);
		os << total;
		os << std::endl;

		return os;
	}

}