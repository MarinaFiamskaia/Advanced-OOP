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
#include "ConfirmOrder.h"

namespace sdds {
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& toCopy) {
		*this = toCopy;
	}
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& toCopy) {
		if (this != &toCopy) {
			co_arrSize = toCopy.co_arrSize;
			delete[] co_arrPtrToy;
			co_arrPtrToy = nullptr;
			if(toCopy.co_arrPtrToy != nullptr){
				co_arrPtrToy = new const Toy * [co_arrSize];
				for (auto i = 0u; i < toCopy.co_arrSize; i++) {
					co_arrPtrToy[i] = toCopy.co_arrPtrToy[i];
				}
			}
		}
		return *this;
	}
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& toMove)noexcept {
		*this = std::move(toMove);
	}
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& toMove)noexcept {
		if (this != &toMove) {
			co_arrSize = toMove.co_arrSize;
			delete[] co_arrPtrToy;
			co_arrPtrToy = nullptr;
			co_arrPtrToy = toMove.co_arrPtrToy;
			toMove.co_arrPtrToy = nullptr;
			toMove.co_arrSize = 0;

		}
		return *this;
	}
	ConfirmOrder::~ConfirmOrder() {
		delete[] co_arrPtrToy;
		co_arrPtrToy = nullptr;
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		bool exist{};
		for (auto i = 0u; i < co_arrSize; i++) {
			if (co_arrPtrToy[i] == &toy)exist = true;
		}
		if (!exist) {
			const Toy** tempArray{};
			tempArray = new const Toy * [co_arrSize + 1];
			for (auto i = 0u; i < co_arrSize; i++) {
				tempArray[i] = co_arrPtrToy[i];
			}
			tempArray[co_arrSize] = &toy;
			co_arrSize++;
			delete[] co_arrPtrToy;
			co_arrPtrToy = nullptr;
			co_arrPtrToy = tempArray;
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		bool exist{};
		size_t index{};

		for (auto i = 0u; i < co_arrSize; i++) {
			if (co_arrPtrToy[i] == &toy) {
				exist = true;
				index = i;
			}
		}
		if (exist) {
			const Toy** tempArray{};
			tempArray = new const Toy * [co_arrSize - 1];
			for (auto i = 0u; i < co_arrSize-1; i++) {
				if (i < index) { 
					tempArray[i] = co_arrPtrToy[i]; 
				}
				else {
					tempArray[i] = co_arrPtrToy[i + 1];
				}
			}
			co_arrSize--;
			delete[] co_arrPtrToy;
			co_arrPtrToy = nullptr;
			co_arrPtrToy = tempArray;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& order) {
		ostr << "--------------------------";
		ostr << std::endl;
		ostr << "Confirmations to Send";
		ostr << std::endl;
		ostr << "--------------------------";
		ostr << std::endl;
		if (order.co_arrSize == 0) {
			ostr << "There are no confirmations to send!";
			ostr << std::endl;
		}
		else {
			for (auto i = 0u; i < order.co_arrSize; i++) {
				if (order.co_arrPtrToy != nullptr)ostr << *(order.co_arrPtrToy[i]);
			}
		}
		ostr << "--------------------------";
		ostr << std::endl;

		return ostr;
	}
}