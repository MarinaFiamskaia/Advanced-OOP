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
#include "Child.h"

namespace sdds {
	Child::Child(const Child& toCopy) {
		*this = toCopy;
	}
	Child& Child::operator=(const Child& toCopy) {
			if (this != &toCopy) {
				c_name = toCopy.c_name;
				c_age = toCopy.c_age;

				for (auto i = 0u; i < c_numOfToys; ++i)
					delete c_arrPtrToy[i];
				delete[] c_arrPtrToy;
				c_arrPtrToy = nullptr;

				if (toCopy.c_arrPtrToy!=nullptr) {
					c_arrPtrToy = new const sdds::Toy * [toCopy.c_numOfToys];
					for (auto i = 0u; i < toCopy.c_numOfToys; i++) {
						c_arrPtrToy[i] = new sdds::Toy(*toCopy.c_arrPtrToy[i]);//received help from Khoi Vu and Jenny Lee
					}
				}
				c_numOfToys = toCopy.c_numOfToys;
			}
		return *this;
	}
	Child::Child(Child&& toMove)noexcept {
		*this = std::move(toMove);
	}
	Child& Child::operator=(Child&& toMove)noexcept {
			if (this != &toMove) {
				c_name = toMove.c_name;
				c_age = toMove.c_age;

				for (auto i = 0u; i < c_numOfToys; ++i)
					delete c_arrPtrToy[i];
				delete[] c_arrPtrToy;
				c_arrPtrToy = nullptr;

				c_numOfToys = toMove.c_numOfToys;
				c_arrPtrToy = toMove.c_arrPtrToy;
				toMove.c_arrPtrToy = nullptr;
				toMove.c_numOfToys = 0;
				toMove.c_name = "\0";
				toMove.c_age = 0;
			}
		return *this;
	}
	Child::~Child() {
		for (auto i = 0u; i < c_numOfToys; ++i)
			delete c_arrPtrToy[i];
		delete[] c_arrPtrToy;
		c_arrPtrToy = nullptr;
	}
	Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
			c_name = name;
			c_age = age;
			c_numOfToys=count;

			if (count > 0) {
				c_arrPtrToy = new const sdds::Toy * [c_numOfToys];
				for (auto i = 0u; i < c_numOfToys; i++) {
					c_arrPtrToy[i] = new sdds::Toy(*toys[i]);
				}
			}
	}
	size_t Child::size() const {
		return c_numOfToys;
	}
	std::ostream& operator<<(std::ostream& ostr, const Child& child) {
		static size_t CALL_CNT{};
		ostr << "--------------------------";
		ostr << std::endl;
		ostr << "Child " << ++CALL_CNT;
		ostr << ": ";
		ostr << child.c_name;
		ostr << " ";
		ostr << child.c_age;
		ostr << " years old:";
		ostr << std::endl;
		ostr << "--------------------------";
		ostr << std::endl;
		if (child.c_numOfToys == 0) {
			ostr << "This child has no toys!";
			ostr << std::endl;
		}
		else {

			for (auto i = 0u; i < child.c_numOfToys; i++) {
				ostr << *(child.c_arrPtrToy[i]);
			}
		}
		ostr << "--------------------------";
		ostr << std::endl;		
		return ostr;
	}
}