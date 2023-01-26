/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 12, 2022
Subject:	OOP345 NAA
Project:	Workshop 4 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H

#include "Toy.h"

namespace sdds {

	class ConfirmOrder {
		const sdds::Toy** co_arrPtrToy{};
		size_t co_arrSize{};
	public:
		ConfirmOrder() {};
		ConfirmOrder(const ConfirmOrder& toCopy);
		ConfirmOrder& operator=(const ConfirmOrder& toCopy);
		ConfirmOrder(ConfirmOrder&& toMove)noexcept;
		ConfirmOrder& operator=(ConfirmOrder&& toMove)noexcept;
		~ConfirmOrder();

		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& order);
	};
}
#endif // !SDDS_CONFIRMORDER_H
