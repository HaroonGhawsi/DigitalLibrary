#include "manageDigiLibBook.h"
#include "digiLibBook.h"
#include "user.h"
#include <string>
#include <vector>


void manageDigiLibBook::addNewBook(){

    //initialize digiLibBook Object.
    digiLibBook bObj;

    //Print book details and get the user input

    std::cout << "\n\n\t------------Add New Book------------";
	std::cout << "\n\tBook Title: ";
	std::cin.ignore();
	getline(std::cin, bObj.bookTitle);
	std::cout << "\tBook Author: ";
	getline(std::cin, bObj.bookAuthor);
	std::cout << "\tBook ISBN: ";
	getline(std::cin, bObj.bookISBN);
	std::cout << "\tBook Publish Year: ";
	getline(std::cin, bObj.bookPublishYear);

    //Save the input to the myBook vector
	myBook.push_back(bObj);

};
void manageDigiLibBook::showBookList(){

    //assign the size of the vector in an unsigned int variable.
    unsigned int size = myBook.size();

    //iterate through vector and display the entered data from vector.

    for (auto &bObj : myBook) {
		std::cout << "\tBook Title:           " << bObj.bookTitle << std::endl;
		std::cout << "\tBook Author:          " << bObj.bookAuthor << std::endl;
		std::cout << "\tBook ISBN:            " << bObj.bookISBN << std::endl;
		std::cout << "\tBook Publish Year:    " << bObj.bookPublishYear << std::endl;
		std::cout << "\t****************************************************" << std::endl;
		std::cout << std::endl;
	}
        std::cout << std::endl;
}
void manageDigiLibBook::modifyBook(){

    int srNo;
    unsigned int size = myBook.size();

        //iterating through vector and displaying each item of each element of the vector
        for(int i=0; i<size; i++){

            std::cout << "\t" << i << " " << "\tBook Title:        " << myBook[i].bookTitle << std::endl;
            srNo = i;
        }
            //Getting input from user to modify the vector element.
            std::cout << std::endl;
            std::cout << "\tSelect a Book to modify: ";
            std::cin>>srNo;
            std::cout << "\tBook Title:         ";
            std::cin.ignore();
            getline(std::cin, myBook[srNo].bookTitle);
            std::cout << "\tBook Author:        ";
            getline(std::cin, myBook[srNo].bookAuthor);
            std::cout << "\tBookISBN:           ";
            getline(std::cin, myBook[srNo].bookISBN);
            std::cout << "\tBookYear:           ";
            getline(std::cin, myBook[srNo].bookPublishYear);
            std::cout << "\tYou have successfully modified Book No. " << srNo << std::endl;
            std::cout << std::endl;
            std::cout << "\t****************************************************" << std::endl;
    }

void manageDigiLibBook::markBookBorrowed(){

         int srNo;
         std::string mborrow;

         unsigned int size = myBook.size();

        for(int i=0; i<size; i++){

            std::cout << "\t" << i << " " << "\tBook Title:        " << myBook[i].bookTitle << std::endl;
            srNo = i;
        }
            std::cout << std::endl;
            std::cout << "\tSelect a book to mark Borrowed: ";
            std::cin>>srNo;
            std::cout << std::endl;
            std::cout << "\tPress (B) or (b) to Mark this Book as Borrowed: ";
            std::cin >> myBook[srNo].bookBorrowed;
            std::cout << std::endl;
            std::cout << "\t" << srNo << " Book Title:      " << myBook[srNo].bookTitle << " marked as Borrowed!" << std::endl;
            std::cout << std::endl;
            std::cout << "\t****************************************************" << std::endl;
}

void manageDigiLibBook::showListOfBorrowedBooks(){

    unsigned int size = myBook.size();

    for(int i=0; i<size; i++){

        std::cout << "\t" << i << " " << "\tBook Title:         " << myBook[i].bookTitle << " " << myBook[i].bookBorrowed << std::endl;
    }
}

