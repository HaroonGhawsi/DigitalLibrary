#ifndef DIGILIBBOOK_H
#define DIGILIBBOOK_H


#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <string>

class digiLibBook
{
    public:


    std::string bookTitle;
    std::string bookAuthor;
    std::string bookISBN;
    std::string bookPublishYear;
    std::string bookBorrowed;


    friend class boost::serialization::access;

    template<typename Archive>


    void serialize(Archive &ar, const unsigned int version){

        ar & bookTitle;
        ar & bookAuthor;
        ar & bookISBN;
        ar & bookPublishYear;
        ar & bookBorrowed;
    }
    protected:
    private:
};

#endif // DIGILIBBOOK_H
