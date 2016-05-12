#ifndef MANAGEDIGILIBBOOK_H
#define MANAGEDIGILIBBOOK_H

#include <iostream>
#include <string>
#include <vector>
#include "digiLibBook.h"

class manageDigiLibBook
{
    public:
        void addNewBook();
    	void showBookList();
        void modifyBook();
    	void markBookBorrowed();
    	//std::string showBorrowedBook();


    protected:
    std::vector<digiLibBook> myBook;
    private:
};


#endif // MANAGEDIGILIBBOOK_H
