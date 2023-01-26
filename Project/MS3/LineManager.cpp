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

#include <fstream>
#include <algorithm>
#include <string>
#include "Utilities.h"
#include "LineManager.h"

namespace sdds {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations){
        std::ifstream infile(file);

        if (!infile)
            throw "ERROR: Cannot open file";
        else {
            Utilities utils;
            bool more{true};
            size_t npos{0};

            std::string fileLine{};
            std::string currStName{};
            std::string nxtStName{};

            Workstation* nxtS{};
            Workstation* currS{};
            Workstation* firstS{};

            while (std::getline(infile, fileLine)){
                currStName = utils.extractToken(fileLine, npos, more);
                currS = *std::find_if(stations.begin(), stations.end(), 
                    [&](Workstation* station){
                    return station->getItemName() == currStName;
                    });
                m_activeLine.push_back(currS);

                if (more){
                    nxtStName = utils.extractToken(fileLine, npos, more);
                    nxtS = *std::find_if(stations.begin(), stations.end(), [&](Workstation* station){
                        return station->getItemName() == nxtStName;
                        });
                    currS->setNextStation(nxtS);
                }
            }

            for_each(stations.begin(), stations.end(), [&](Workstation* tmp){
                firstS = *find_if(stations.begin(), stations.end(), [&](Workstation* station){
                    return station->getNextStation() == firstS;
                    });
                });

            m_firstStation = firstS;
        }
        infile.close();
        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations(){
        std::vector<Workstation*> sort{};

        sort.push_back(m_firstStation);
        sort.push_back(m_firstStation->getNextStation());
        std::for_each(m_activeLine.begin(), m_activeLine.end() - 2,
            [&](Workstation* station) {
                sort.push_back(sort.back()->getNextStation());
            });
        m_activeLine = sort;
    }
    bool LineManager::run(std::ostream& os){
        static size_t itr{};
        os << "Line Manager Iteration: " 
            << ++itr 
            << std::endl;

        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        std::for_each(m_activeLine.begin(), m_activeLine.end(), 
            [&](Workstation* station){
                station->fill(os);
            });

        std::for_each(m_activeLine.begin(), m_activeLine.end(), 
            [](Workstation* station){
                station->attemptToMoveOrder();
            });
        return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
    }
    void LineManager::display(std::ostream& os) const{
        if (!m_activeLine.empty())
            std::for_each(m_activeLine.begin(), m_activeLine.end(),
                [&](Workstation* station) {
                    station->display(os);
                });
    }
}