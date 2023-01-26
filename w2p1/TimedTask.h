/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		May 30, 2022
Subject:	OOP345 NAA
Project:	Workshop 2 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H
#include <iostream>
#include <chrono>

namespace sdds {
	const int maxNumOfObjects = 10;

	class TimedTask {
		int tt_numOfRecords{};
		std::chrono::steady_clock::time_point tt_start{};
		std::chrono::steady_clock::time_point tt_end{};
		struct {
			std::string t_taskName{};
			std::string t_unitsOfTime{};
			std::chrono::steady_clock::duration t_duration{};
		}task[maxNumOfObjects];
	public:
		TimedTask() {};
		void startClock();
		void stopClock();
		void addTask(const char* str);

		friend std::ostream& operator<<(std::ostream& ostr, const TimedTask& inc);
	};
}

#endif // !SDDS_TIMEDTASK_H
