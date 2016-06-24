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
 os << "Book Title:         " << odb.bookTitle << std::endl;
 os << "Book Author:        " << odb.bookAuthor << std::endl;
 os << "Book ISBN:          " << odb.bookISBN << std::endl;
 os << "Book Publish Year:  " << odb.bookPublishYear << std::endl;
 os << "******************************************" << std::endl;

}

digiLibData::digiLibData(){}

digiLibData::~digiLibData(){}


std::string digiLibData::saveNewBookToMemory(std::string inputmessage){

    try{
        std::stringstream ss;
        ss << inputmessage;
        boost::archive::text_iarchive ia{ss};
        ia >> sObj;

        serverData.push_back(sObj);
        return "Book Added";
    }
    catch(std::exception& e){

        std::cerr << e.what() << std::endl;
    }
}

std::string digiLibData::showAllBooksFromMemory(){

    typedef boost::asio::ip::tcp asiotcp;
    std::stringstream ss;

    boost::archive::text_oarchive oa{ss};
    oa & serverData;
    std::string output = ss.str();
    return output;
}

std::string digiLibData::updateBookInMemory(std::string modBook){

    try{

        digiLibBook tempObj;
        std::stringstream ss;
        ss << modBook;
        boost::archive::text_iarchive ia{ss};
        ia >> tempObj;

        for(int i = 0; i < serverData.size(); i++){

            if(tempObj.bookISBN == serverData[i].bookISBN){
                serverData.erase(serverData.begin()+i);
                serverData.push_back(tempObj);
                return "Book Updated";
            }
        }
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return "Book Not Updated";
}


std::string digiLibData::markBookBorrowedInMemory(std::string markBook){
    //Server data is already serialized and sent to client, marking borrowed will be saved to Server.

    try{

        digiLibBook d;
        std::stringstream ss;
        ss << markBook;
        boost::archive::text_iarchive ia{ss};
        ia >> d;

        for(int i = 0; i < serverData.size(); i++){

            if(d.bookISBN == serverData[i].bookISBN){
                serverData[i].bookBorrowed = d.bookBorrowed;
                return "Book Borrowed";
            }
        }
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return "Book Not Borrowed";
}


std::string digiLibData::showAllBorrowedBooksFromMemory(){

    //Will show list of Borrowed Books from the server
    typedef boost::asio::ip::tcp asiotcp;
    std::stringstream ss;

    boost::archive::text_oarchive oa{ss};
    oa & serverData;
    std::string output = ss.str();
    return output;
};


