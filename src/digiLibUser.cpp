#include "ManageDigiLibBooks.h"
#include "digiLibUser.h"
#include <iostream>


digiLibUser::digiLibUser(){
}

digiLibUser::~digiLibUser(){
}

void digiLibUser::userNavigationMenu(){

    system("clear");
    std::cout << "**************************************************\n";
    std::cout << "Welcome to Digital Library\n";
    std::cout << "**************************************************\n";
    std::cout << "Press 1 to Add New Book to the Library\n";
    std::cout << "Press 2 to Modify existing Library book\n";
    std::cout << "Press 3 to View list of available books in the library\n";
    std::cout << "Press 4 to Mark books as borrowed\n";
    std::cout << "Press 5 to View list of borrowed books in the library\n";
    std::cout << "Press 0 to Exit\n";
    std::cin >> userSelection;
    mBooks->userRequestProcessor(userSelection);
    delete mBooks;
}

int main(int argc, char *argv[]){

    digiLibUser *dUser = new digiLibUser();
    dUser->userNavigationMenu();
    delete dUser;
}
