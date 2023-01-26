/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		July 25, 2022
Subject:	OOP345 NAA
Project:	Workshop 8 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
    GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;
        // TODO: Add your code here to build a list of employees
        //         using raw pointers
        for (size_t i = 0; i < emp.size(); i++) {
            for (size_t j = 0; j < sal.size(); j++) {
                if (emp[i].id == sal[j].id) {
                    EmployeeWage empWage(emp[i].name, sal[j].salary);
                    empWage.rangeValidator();
                    if (activeEmp.checkLuhn(emp[i].id))
                        activeEmp += empWage;
                    else
                        throw "*** Employees salaray id is not valid";
                }
            }
        }
        return activeEmp;
    }
}