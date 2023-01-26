/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		August 3, 2022
Subject:	OOP345 NAA
Project:	Final Project MS2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include<iostream>
#include "Station.h"

namespace sdds {
	struct Item{
		std::string m_itemName{};
		size_t m_serialNumber{0};
		bool m_isFilled{false};

		Item(const std::string& src) : m_itemName(src){};
	};

	class CustomerOrder{
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};

		static size_t m_widthField;
	public:
		CustomerOrder() {};
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder& toCopy);
		CustomerOrder& operator=(const CustomerOrder& toCopy) = delete;
		CustomerOrder(CustomerOrder&& toMove)noexcept;
		CustomerOrder& operator=(CustomerOrder&& toMove)noexcept;
		virtual ~CustomerOrder();

		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif