#include "digiLibBook.h"

digiLibBook::digiLibBook(){
}

digiLibBook::~digiLibBook(){
}

    void digiLibBook::set_bookTitle(std::string bookTitle){
        bookTitle = bookTitle;
}
    void digiLibBook::set_bookAuthor(std::string bookAuthor){
    bookAuthor = bookAuthor;
}
    void digiLibBook::set_bookISBN(std::string bookISBN){
    bookISBN = bookISBN;
}
    void digiLibBook::set_bookPublishYear(std::string bookPublishYear){
    bookPublishYear = bookPublishYear;
}
    std::string digiLibBook::get_bookTitle(){
    return bookTitle;
}
    std::string digiLibBook::get_bookAuthor(){
    return bookAuthor;
}
    std::string digiLibBook::get_bookISBN(){
    return bookISBN;
}
    std::string digiLibBook::get_bookPublishYear(){
    return bookPublishYear;
}
