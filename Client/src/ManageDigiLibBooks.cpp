#include "ManageDigiLibBooks.h"

#include <stdlib.h>
#include <limits>
#include "digiLibUser.h"
#include "unistd.h"
#include "stdio.h"
#include "digiLibBook.h"
#include "digiLibClient.h"

ManageDigiLibBooks::ManageDigiLibBooks(){}

ManageDigiLibBooks::~ManageDigiLibBooks(){}

void ManageDigiLibBooks::addNewBook(){

    std::vector<std::string> newBook;
    std::string _bTitle, _bAuthor, _bISBN, _bPublishYear;
    char result;

    system("clear");
    std::cout << "*****************************************\n";
    std::cout << "Please add New Book\n";
    std::cout << "*****************************************\n";
    std::cout << "Please enter the New Book Title: ";
    getline(std::cin, _bTitle);
    std::cout << "Please enter the New Book Author: ";
    getline(std::cin, _bAuthor);
    std::cout << "Please enter the New Book ISBN: ";
    getline(std::cin, _bISBN);
    std::cout << "Please enter the New Book Publish Year: ";
    getline(std::cin, _bPublishYear);

    newBook.push_back(_bTitle);
    newBook.push_back(_bAuthor);
    newBook.push_back(_bISBN);
    newBook.push_back(_bPublishYear);

    std::cout << "\nWould you like to add more Books? Press Y if yes else N for No: ";
    std::cin >> result;

    if(result == 'Y' || result == 'y'){
        addNewBook();
    }
    else {
        std::cout << "Your New Book entry has been saved!";
    }
}



