/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 20, 2022
Subject:	OOP345 NAA
Project:	Workshop 5 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <iostream>
#include <string>

namespace sdds {
	template <typename T>
	class Collection {
		std::string c_name{};
		T* c_objArr{};
		size_t c_arrSize{};
		void (*c_observerPtr)(const Collection<T>&, const T&) {};
	public:
		Collection(const std::string& name) {
			if (!name.empty()) {
				c_name = name;
				c_objArr = nullptr;
				c_arrSize = 0;
				c_observerPtr = nullptr;
			}
		}
		Collection(Collection& toCopy) = delete;
		Collection& operator=(Collection& toCopy) = delete;
		Collection(Collection&& toMove) = delete;
		Collection& operator=(Collection&& toMove) = delete;
		~Collection() {
			delete[] c_objArr;
			c_objArr = nullptr;
		}
		const std::string& name() const {
			return c_name;
		}
		size_t size() const {
			return c_arrSize;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			c_observerPtr = observer;
		}
		Collection<T>& operator+=(const T& item) {
			bool exist{};
			for (auto i = 0u; i < c_arrSize;i++) {
				if (c_objArr[i].title() == item.title())exist = true;
			}
			if (!exist) {
				T* tempArray = new T[c_arrSize + 1];
				for (auto i= 0u; i < c_arrSize; i++) {
					tempArray[i] = c_objArr[i];
				}
				tempArray[c_arrSize] = item;
				delete[] c_objArr;
				c_objArr = nullptr;
				c_arrSize++;
				c_objArr = new T[c_arrSize];
				for (auto i= 0u; i < c_arrSize; i++) {
					c_objArr[i] = tempArray[i];
				}
				delete[] tempArray;
				if (c_observerPtr != nullptr)c_observerPtr(*this, item);
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= c_arrSize) {
				std::string message = { "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_arrSize) + "] items." };
				throw std::out_of_range(message);
			}
			else {
				return c_objArr[idx];
			}
		}
		T* operator[](const std::string& title) const {
			size_t index{};
			bool exist{};
			for (auto i = 0u; i < c_arrSize; i++) {
				if (c_objArr[i].title() == title) {
					index = i;
					exist = true;
				}
			}
			if (!exist)return nullptr;
			return &c_objArr[index];
		}
		friend std::ostream& operator<<(std::ostream& ostr, Collection& collection){
			for (auto i = 0u; i < collection.c_arrSize; i++) {
				ostr << collection.c_objArr[i];
			}
			return ostr;
		}
	};
}
#endif // !SDDS_COLLECTION_H