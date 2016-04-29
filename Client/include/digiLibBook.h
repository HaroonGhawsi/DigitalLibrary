#ifndef DIGILIBBOOK_H
#define DIGILIBBOOK_H

#include <string>

class digiLibBook
{
    public:
        digiLibBook();
        virtual ~digiLibBook();

        void set_bookTitle(std::string bookTitle);
        void set_bookAuthor(std::string bookAuthor);
        void set_bookISBN(std::string bookISBN);
        void set_bookPublishYear(std::string bookPublishYear);

        std::string get_bookTitle();
        std::string get_bookAuthor();
        std::string get_bookISBN();
        std::string get_bookPublishYear();

    protected:
    private:

    std::string bookTitle;
    std::string bookAuthor;
    std::string bookISBN;
    std::string bookPublishYear;

};

#endif // DIGILIBBOOK_H
