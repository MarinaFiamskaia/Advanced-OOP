/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		August 7, 2022
Subject:	OOP345 NAA
Project:	Final Project MS3

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include "CustomerOrder.h"

namespace sdds {
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete; 

    class Workstation : public Station {
        std::deque<CustomerOrder> m_orders{};
        Workstation* m_pNextStation{};

    public:
        Workstation(const std::string& str) : Station(str) {};
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);


        Workstation(const Workstation& toCopy) = delete;
        Workstation& operator=(const Workstation& toCopy) = delete;
        Workstation(Workstation&& toMove) = delete;
        Workstation& operator=(Workstation&& toMove) = delete;
    };
}
#endif
