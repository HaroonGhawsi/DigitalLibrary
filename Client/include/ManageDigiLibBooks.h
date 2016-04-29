#ifndef MANAGEDIGILIBBOOKS_H
#define MANAGEDIGILIBBOOKS_H


class ManageDigiLibBooks
{
    public:
        ManageDigiLibBooks();
        virtual ~ManageDigiLibBooks();

        void addNewBook();
        void modifyBook();
        void showListOfBooks();
        void markBookAsBorrowed();
        void showListOfBorrowedBooks();
        void userRequestProcessor(int uRequest);


    protected:
    private:
};

#endif // MANAGEDIGILIBBOOKS_H
