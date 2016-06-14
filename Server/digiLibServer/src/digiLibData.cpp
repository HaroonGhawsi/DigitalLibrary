#include "digiLibData.h"
#include "digiLibBook.h"
#include "digiLibData.h"
#include "digiLibServer.h"
#include <iostream>
#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/serialization/vector.hpp>


typedef boost::asio::ip::tcp asiotcp;

//std::ostream &operator<<(std::ostream &os, digiLibBook const &odb){
void dumpBook(digiLibBook const &odb)
{
 std::ostream &os = std::cout;
 os << "Book Title: " << odb.bookTitle << std::endl;
 os << "Book Author: " << odb.bookAuthor << std::endl;
 os << "Book ISBN: " << odb.bookISBN << std::endl;
 os << "Book Publish Year: " << odb.bookPublishYear << std::endl;

}

digiLibBook sObj;

digiLibData::digiLibData(){}

digiLibData::~digiLibData(){}

void digiLibData::saveNewBookToMemory(std::string inputmessage){
try{

    std::cout << "Saving New Book to the Server Memory" << std::endl;

    std::stringstream ss;
    ss << inputmessage;
    boost::archive::text_iarchive ia{ss};
    ia >> sObj;
    serverData.push_back(sObj);
    dumpBook(sObj);

    }
    catch(std::exception& e){

    std::cerr << e.what() << std::endl;
    }
}


