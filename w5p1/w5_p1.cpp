/*
Student:	Marina Fiamskaia
Student ID:	025-698-051
email:		mfiamska@myseneca.ca
Date:		June 19, 2022
Subject:	OOP345 NAA
Project:	Workshop 5 part 1

****I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.****
*/

// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	if (argc == 2) {
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
		//       - if the file cannot be open, print a message to standard error console and
		//                exit from application with error code "AppErrors::CannotOpenFile"

		std::ifstream file(argv[1]);
		if (!file) {
			std::cout << "ERROR: Cannot open file [" << argv[1] << "]" << std::endl;
			exit(AppErrors::CannotOpenFile);
		}

		std::string strBook{};
		size_t cnt{};
		do {
			//std::cout << "entered do while reading" << std::endl;
			std::getline(file, strBook);
			//std::cout << "read: " << strBook << std::endl;
			if (file) {
				if (strBook[0] != '#') {
					if (cnt < 7) {
						library[cnt] = Book(strBook);
						cnt++;
					}
				}
			}
		} while (file);
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto priceAdjust = [usdToCadRate, gbpToCadRate](Book& inc) {
		if (inc.country() == "US") {
			inc.price() *= usdToCadRate;
		}
		else if (inc.country() == "UK" && inc.year() >= 1990 && inc.year() <= 1999) {
			inc.price() *= gbpToCadRate;
		}
		//should i have return here?????
	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (auto& book : library)
		std::cout << book;


	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (auto& book : library)
		priceAdjust(book);


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (auto& book : library)
		std::cout << book;


	std::cout << "-----------------------------------------\n";

	return 0;
}
