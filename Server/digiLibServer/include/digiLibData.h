#ifndef DIGILIBDATA_H
#define DIGILIBDATA_H

#include "digiLibBook.h"
#include <vector>


class digiLibData
{
    public:
        digiLibData();
        virtual ~digiLibData();

        void saveNewBookToMemory(std::string);
        void updateBookInMemory();
        void showAllBooksFromMemory();
        void markBookBorrowedInMemory();
        void showAllBorrowedBooksFromMemory();

    protected:


    private:

    std::vector<digiLibBook> serverData;


};

#endif // DIGILIBDATA_H
