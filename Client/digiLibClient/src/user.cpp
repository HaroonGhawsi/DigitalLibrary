#include "user.h"
#include "digiLibBook.h"
#include "manageDigiLibBook.h"
#include <string>
#include <iostream>


void user::showMainMenu()
{
	char choice[6];

	std::cout << "\n\t\t Digital Library\n";

	while (choice[0] != '0')
	{
		std::cout << "\n\t------------Main Menu------------\n";
		std::cout << "\n\t|				   |";
		std::cout << "\n\t|	(1)Add New Book		   |";
		std::cout << "\n\t|	(2)Show List of Books	   |";
		std::cout << "\n\t|	(3)Modify Book		   |";
		std::cout << "\n\t|	(4)Mark Books as Borrowed  |";
		std::cout << "\n\t|	(5)Show list of Borrowed   |";
		std::cout << "\n\t|	(0)Exit Main Menu   |";
		std::cout << "\n\t|				   |";
		std::cout << "\n\t---------------------------------\n";
		std::cout << "\n\t";
		std::cin >>choice;
		std::cout << std::endl;

		switch(choice[0])
        {
            case '1' : m_lib.addNewBook(); break;
            case '2' : m_lib.showBookList(); break;
            case '3' : m_lib.modifyBook(); break;
            case '4' : m_lib.markBookBorrowed(); break;
            case '5' : m_lib.showListOfBorrowedBooks(); break;
            case '0' : std::cout << "\n\tExiting Main Menu..." << std::endl;
                        break;
            default : "\n\tInvalid Input";
        }
    }



}
