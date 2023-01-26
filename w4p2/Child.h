/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 12, 2022
Subject:	OOP345 NAA
Project:	Workshop 4 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H

#include <iostream>
#include <string>
#include "Toy.h"

namespace sdds {
	class Child {//composition
		const sdds::Toy** c_arrPtrToy{};
		std::string c_name{};
		size_t c_age{};
		size_t c_numOfToys{};

	public:
		Child() {};
		Child(const Child& toCopy);
		Child& operator=(const Child& toCopy);
		Child(Child&& toMove)noexcept;
		Child& operator=(Child&& toMove)noexcept;
		~Child();

		Child(std::string name, int age, const Toy* toys[], size_t count);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& ostr, const Child& child);
	};

}
#endif // !SDDS_CHILD_H
