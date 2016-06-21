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

void digiLibData::showAllBooksFromMemory(Socket &socket){

    std::stringstream ss;
    typedef boost::asio::ip::tcp asiotcp;

    unsigned int size = serverData.size();

    //iterate through vector and display the entered data from vector.

    for (auto &sObj : serverData) {
		std::cout << "\tBook Title:           " << sObj.bookTitle << " " << sObj.bookBorrowed << std::endl;
		std::cout << "\tBook Author:          " << sObj.bookAuthor << std::endl;
		std::cout << "\tBook ISBN:            " << sObj.bookISBN << std::endl;
		std::cout << "\tBook Publish Year:    " << sObj.bookPublishYear << std::endl;
		std::cout << "\t****************************************************" << std::endl;
		std::cout << std::endl;
	}
        std::cout << std::endl;
        boost::archive::text_oarchive oa{ss};
        oa << serverData;
        std::string output = ss.str();
        socket.send(boost::asio::buffer(output));
}
void digiLibData::updateBookInMemory(){

    //update the same index data from the client. serverData vector is already sent to Client.
}
void digiLibData::markBookBorrowedInMemory(){
    //Server data is already serialized and sent to client, marking borrowed will be saved to Server.
}

void digiLibData::showAllBorrowedBooksFromMemory(){

    //Will show list of Borrowed Books from the server

};


