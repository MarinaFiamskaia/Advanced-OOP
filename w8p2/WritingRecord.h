/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 26, 2022
Subject:	OOP345 NAA
Project:	Workshop 8 part 2

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_WRITINGRECORD_H
#define SDDS_WRITINGRECORD_H

#include "GeneratingList.h"
#include "EmpProfile.h"

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal);
}


#endif // SDDS_WRITINGRECORD_H

