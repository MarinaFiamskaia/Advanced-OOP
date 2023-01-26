/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		August 3, 2022
Subject:	OOP345 NAA
Project:	Final Project MS2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {
	size_t CustomerOrder::m_widthField=0;

	CustomerOrder::CustomerOrder(const std::string& str) {
		size_t next_pos{};
		bool more{ true };
		Utilities utility;

		try {
			m_name = more ? utility.extractToken(str, next_pos, more) : "";
			m_product = more ? utility.extractToken(str, next_pos, more) : "";
			m_cntItem = more ? std::count(str.begin(), str.end(), utility.getDelimiter())-1 : 0;
			m_lstItem = new Item*[m_cntItem];
			for (auto i = 0u; i < m_cntItem;++i){
				m_lstItem[i] = new Item(utility.extractToken(str, next_pos, more));
			}
			m_widthField = std::max(utility.getFieldWidth(), m_widthField);
		}
		catch (std::string& msg) {
			std::cout << msg;
		}
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& toCopy) {
		throw "The copy operation is not allowed!";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& toMove)noexcept {
		*this = std::move(toMove);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& toMove)noexcept {
		if (this != &toMove) {
			m_name = toMove.m_name;
			m_product = toMove.m_product;

			for (auto i = 0u; i < m_cntItem; ++i)
				delete m_lstItem[i];
			delete[] m_lstItem;
			m_lstItem = nullptr;

			m_cntItem = toMove.m_cntItem;
			m_lstItem = toMove.m_lstItem;
			toMove.m_lstItem = nullptr;
			toMove.m_cntItem = 0;
			toMove.m_name = "\0";
			toMove.m_product = "\0";
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder(){
		for (size_t i = 0; i < m_cntItem; i++)
			delete m_lstItem[i]; 
		delete[] m_lstItem;
	}
	bool CustomerOrder::isOrderFilled() const {
		//perhaps use algorithm any, all, none?
		for (auto i = 0u; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_isFilled == false)
				return false;
		}
		return true;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		for (auto i = 0u; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == itemName)
				return m_lstItem[i]->m_isFilled;
		}
		return true;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (auto i = 0u; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity()>0) {
				station.updateQuantity();
				m_lstItem[i]->m_isFilled = true;
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				os << "\tFilled ";
				os << m_name;
				os << ", ";
				os << m_product;
				os << " [";
				os << m_lstItem[i]->m_itemName;
				os << "]";
				os << std::endl;
			}
			else if(m_lstItem[i]->m_itemName == station.getItemName() && station.getQuantity()==0) {
				os << "Unable to fill ";
				os << m_name;
				os << ", ";
				os << m_product;
				os << " [";
				os << m_lstItem[i]->m_itemName;
				os << "]";
				os << std::endl;
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name;
		os << " - ";
		os << m_product;
		os << std::endl;
		for (auto i = 0u; i < m_cntItem; ++i) {
			os << "[";
			os.setf(std::ios::right);
			os.width(6);
			os.fill('0');
			os << m_lstItem[i]->m_serialNumber;
			os << "] ";
			os.unsetf(std::ios::right);
			os.setf(std::ios::left);
			os.width(m_widthField);
			os.fill(' ');
			os << m_lstItem[i]->m_itemName;
			os << "   - ";
			os << (m_lstItem[i]->m_isFilled? "FILLED" : "TO BE FILLED");
			os << std::endl;
		}
	}
}