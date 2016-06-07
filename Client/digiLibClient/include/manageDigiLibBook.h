#ifndef MANAGEDIGILIBBOOK_H
#define MANAGEDIGILIBBOOK_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "digiLibBook.h"


class manageDigiLibBook
{


    public:
        void addNewBook();
    	void showBookList();
        void modifyBook();
    	void markBookBorrowed();
    	void showListOfBorrowedBooks();


    protected:

    std::vector<digiLibBook> myBook;



    private:


};


#endif // MANAGEDIGILIBBOOK_H
