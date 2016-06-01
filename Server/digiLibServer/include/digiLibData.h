#ifndef DIGILIBDATA_H
#define DIGILIBDATA_H

#include "digiLibBook.h"
#include <map>


class digiLibData
{
    public:
        digiLibData();
        virtual ~digiLibData();

        void saveNewBookToMemory();
        void updateBookInMemory();
        void showAllBooksFromMemory();
        void markBookBorrowedInMemory();
        void showAllBorrowedBooksFromMemory();

    protected:


    private:

    static std::map<int, digiLibBook> serverData;


};

#endif // DIGILIBDATA_H
