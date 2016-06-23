#include "digiLibData.h"
#include "digiLibBook.h"
#include "digiLibData.h"
#include "digiLibServer.h"
#include <iostream>
#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/serialization/vector.hpp>


typedef boost::asio::ip::tcp asiotcp;
digiLibBook sObj;

void dumpBook(digiLibBook const &odb)
{
 std::ostream &os = std::cout;
 os << "\n******************************************" << std::endl;
 os << "Book Title: " << odb.bookTitle << std::endl;
 os << "Book Author: " << odb.bookAuthor << std::endl;
 os << "Book ISBN: " << odb.bookISBN << std::endl;
 os << "Book Publish Year: " << odb.bookPublishYear << std::endl;
 os << "******************************************" << std::endl;

}

digiLibData::digiLibData(){}

digiLibData::~digiLibData(){}

void digiLibData::saveNewBookToMemory(std::string inputmessage){

try{

    std::stringstream ss;
    ss << inputmessage;
    boost::archive::text_iarchive ia{ss};
    ia >> sObj;

    serverData.push_back(sObj);
    //dumpBook(sObj);

    std::cout << "\n --> New Book has been saved to Server memory!" << std::endl;

    }
    catch(std::exception& e){

    std::cerr << e.what() << std::endl;
    }
}

void digiLibData::showAllBooksFromMemory(){

    unsigned int size = serverData.size();

    //iterate through vector and display the entered data from vector.

    for (digiLibBook sObj : serverData) {
        /*
        std::string bookTitle = sObj.bookTitle;
        std::string bookAuthor = sObj.bookAuthor;
        std::string bookBorrowed = sObj.bookBorrowed;
        std::string bookISBN = sObj.bookISBN;
        std::string bookPublishYear = sObj.bookPublishYear;
        std::cout << listOfAllBooks << std::endl;
        */

    typedef boost::asio::ip::tcp asiotcp;
    std::stringstream ss;

    boost::archive::text_oarchive oa{ss};
    oa << sObj;

    std::string output = ss.str();

    boost::asio::io_service io_service;
    asiotcp::endpoint server_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"), 4000);
    asiotcp::socket socket(io_service);
    socket.open(asiotcp::v4());
    socket.connect(server_endpoint);
    //std::cout << "Server Show list of Books" << output << std::endl;
    socket.send(boost::asio::buffer(output));

    //std::cout << "this is from show all books " << output << std::endl;
    }

}
/*
void digiLibData::updateBookInMemory(){

    //update the same index data from the client. serverData vector is already sent to Client.

    std::cout << "The Book has been modified in Server Memory" << std::endl;
}
void digiLibData::markBookBorrowedInMemory(){
    //Server data is already serialized and sent to client, marking borrowed will be saved to Server.

    std::cout << " Book has been marked borrowed " << std::endl;
}

void digiLibData::showAllBorrowedBooksFromMemory(){

    //Will show list of Borrowed Books from the server
    std::cout << "List of Borrowed Books" << std::endl;

};
*/

