#ifndef DIGILIBDATA_H
#define DIGILIBDATA_H

#include "digiLibBook.h"
#include <vector>


class digiLibData
{
    public:
        digiLibData();
        virtual ~digiLibData();

        std::string saveNewBookToMemory(std::string);
        std::string showAllBooksFromMemory();
        std::string updateBookInMemory(std::string modBook);
        std::string markBookBorrowedInMemory(std::string markBook);
        std::string showAllBorrowedBooksFromMemory();


    protected:


    private:

    std::vector<digiLibBook> serverData;


};

#endif // DIGILIBDATA_H
