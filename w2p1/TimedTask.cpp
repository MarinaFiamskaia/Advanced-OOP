/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		May 30, 2022
Subject:	OOP345 NAA
Project:	Workshop 2 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/
#define  _CRT_SECURE_NO_WARNINGS

#include "TimedTask.h"

namespace sdds {
	
	void TimedTask::startClock() {
		tt_start = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock() {
		tt_end = std::chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* str) {
		if (str != nullptr && str[0] != 0) {
			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(tt_end - tt_start);
			if (tt_numOfRecords < maxNumOfObjects) {
				task[tt_numOfRecords].t_taskName = str;
				task[tt_numOfRecords].t_unitsOfTime = "nanoseconds";
				task[tt_numOfRecords].t_duration = duration;

				tt_numOfRecords++;
			}
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const TimedTask& inc) {
		ostr << "Execution Times:" << std::endl;
		ostr << "--------------------------" << std::endl;
		for (int i = 0; i < inc.tt_numOfRecords; i++) {
			ostr.setf(std::ios::left);
			ostr.width(21);
			ostr << inc.task[i].t_taskName;
			ostr.unsetf(std::ios::left);
			ostr.setf(std::ios::right);
			ostr.width(13);
			ostr << inc.task[i].t_duration.count();
			ostr.unsetf(std::ios::right);
			ostr << inc.task[i].t_unitsOfTime;
			ostr << std::endl;
		}
		ostr << "--------------------------";
		ostr << std::endl;

		return ostr;
	}
}