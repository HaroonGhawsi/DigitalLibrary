#include "manageDigiLibBook.h"
#include "digiLibBook.h"
#include <string>
#include <vector>


//manageDigiLibBook::manageDigiLibBook(){}

//manageDigiLibBook::~manageDigiLibBook(){}

void manageDigiLibBook::addNewBook(){

    digiLibBook bObj;

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

	myBook.push_back(bObj);

};
void manageDigiLibBook::showBookList(){

    unsigned int size = myBook.size();

    for (auto &bObj : myBook) {
		std::cout << "\tBook Title:           " << bObj.bookTitle << std::endl;
		std::cout << "\tBook Author:          " << bObj.bookAuthor << std::endl;
		std::cout << "\tBook ISBN:            " << bObj.bookISBN << std::endl;
		std::cout << "\tBook Publish Year:    " << bObj.bookPublishYear << std::endl;
		std::cout << "\t****************************************************" << std::endl;
	}
	std::cout << std::endl;
}
void manageDigiLibBook::modifyBook(){

    unsigned int size = myBook.size();

           for(int i=0; i<size; i++){

        std::cout << "\t" << i << " " << "\tBook Title:        " << myBook[i].bookTitle << std::endl;
           }
}
