/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		August 7, 2022
Subject:	OOP345 NAA
Project:	Final Project MS3

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include "Workstation.h"

namespace sdds {
    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    void Workstation::fill(std::ostream& os){
        if (!m_orders.empty())
            m_orders.front().fillItem(*this, os);
    }
    bool Workstation::attemptToMoveOrder(){
        bool result{};
        if (!m_orders.empty()) {
            bool itemFilled = m_orders.front().isItemFilled(getItemName());

            if (itemFilled ||
                (!itemFilled && !getQuantity())) {
                if (!!m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());
                }
                else {
                    if (m_orders.front().isOrderFilled())
                        g_completed.push_back(std::move(m_orders.front()));
                    else
                        g_incomplete.push_back(std::move(m_orders.front()));
                }
                m_orders.pop_front();
                result = true;
            }
        }
        return result;
    }
    void Workstation::setNextStation(Workstation* station){
        if (m_pNextStation != nullptr) 
            delete m_pNextStation;
        m_pNextStation = station;
    }
    Workstation* Workstation::getNextStation() const{
        return m_pNextStation;
    }
    void Workstation::display(std::ostream& os) const{
        os << getItemName() 
            << " --> " 
            << (m_pNextStation == nullptr ? "End of Line" : m_pNextStation->getItemName()) 
            << '\n';
    }
    Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}