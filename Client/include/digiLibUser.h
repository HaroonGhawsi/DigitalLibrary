#ifndef DIGILIBUSER_H
#define DIGILIBUSER_H

#include <iostream>
#include "ManageDigiLibBooks.h"

class digiLibUser
{
    public:
        digiLibUser();
        virtual ~digiLibUser();

        void userNavigationMenu();

    protected:
    private:

    int userSelection;
    ManageDigiLibBooks *mBooks;
};

#endif // DIGILIBUSER_H
