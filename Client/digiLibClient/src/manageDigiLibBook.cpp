#include "manageDigiLibBook.h"
#include "digiLibBook.h"
#include "user.h"
#include <string>
#include <vector>
#include <sstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>


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


digiLibBook bObj;
void manageDigiLibBook::addNewBook(){

    //initialize digiLibBook Object.

    std::stringstream ss;
    typedef boost::asio::ip::tcp asiotcp;

    //Print book details and get the user input

    std::cout << "\n\n\t------------Add New Book------------";
	std::cout << "\n\tBook Title:            ";
	std::cin.ignore();
	getline(std::cin, bObj.bookTitle);
	std::cout << "\tBook Author:            ";
	getline(std::cin, bObj.bookAuthor);
	std::cout << "\tBook ISBN:              ";
	getline(std::cin, bObj.bookISBN);
	std::cout << "\tBook Publish Year:      ";
	getline(std::cin, bObj.bookPublishYear);

    //Save the input to the myBook vector
	//myBook.push_back(bObj);
    boost::archive::text_oarchive oa{ss};
    oa << bObj;
    //std::cout << "Serialized the book ";
    std::string output = ss.str() + "+"+"1";

   // std::cout << output << std::endl; //Output Serialized data

    boost::asio::io_service io_service;
    asiotcp::endpoint server_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"), 4000);
    asiotcp::socket socket(io_service);
    socket.open(asiotcp::v4());
    socket.connect(server_endpoint);
    socket.send(boost::asio::buffer(output));


    std::array<char, 128> recv_buf;
    size_t const len = socket.receive(boost::asio::buffer(recv_buf));
    std::string const received_message(recv_buf.data(), len);
    std::cout << "received from server: " << received_message << std::endl;

};
void manageDigiLibBook::showBookList(){

    /*myBook.clear();



    boost::archive::text_oarchive oa{ss};
    oa << bObj;*/
    typedef boost::asio::ip::tcp asiotcp;
    std::stringstream ss;
    std::string output = ss.str() + "+" + "2";

    // sending Request
    boost::asio::io_service io_service;
    asiotcp::endpoint server_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"), 4000);
    asiotcp::socket socket(io_service);
    socket.open(asiotcp::v4());
    socket.connect(server_endpoint);
    socket.send(boost::asio::buffer(output));

    // Receiving Response
    std::array<char, 128> recv_buf;
    size_t const len = socket.receive(boost::asio::buffer(recv_buf));
    //digiLibBook tempObj;
    std::string received_message(recv_buf.data(), len);

        std::stringstream ss1;
        ss1 << received_message;
        boost::archive::text_iarchive oa1{ss1};
        oa1 & myBook;
        std::cout << myBook.size() << std::endl;

        for(int i=0;i<myBook.size();i++){
            dumpBook(myBook[i]);
        }
}
void manageDigiLibBook::modifyBook(){

    digiLibBook t;
    unsigned int size = myBook.size();
    int srNo;

        //iterating through vector and displaying each item of each element of the vector
        for(int i=0; i<size; i++){
            std::cout << "\t" << i << " " << "\tBook Title:        " << myBook[i].bookTitle << std::endl;
        }
            //Getting input from user to modify the vector element.
            std::cout << std::endl;
            std::cout << "\tSelect a Book to modify: ";
            std::cin>>srNo;
            std::cout << "\tBook Title:         ";
            std::cin.ignore();
            getline(std::cin, t.bookTitle);
            std::cout << "\tBook Author:        ";
            getline(std::cin, t.bookAuthor);
            std::cout << "\tBookISBN:           ";
            getline(std::cin, t.bookISBN);
            std::cout << "\tBookYear:           ";
            getline(std::cin, t.bookPublishYear);
            std::cout << "\tYou have successfully modified Book No. " << srNo << std::endl;
            std::cout << std::endl;
            std::cout << "\t****************************************************" << std::endl;

            std::stringstream ss;
            typedef boost::asio::ip::tcp asiotcp;
            boost::archive::text_oarchive oa{ss};
            oa << t;
            std::string output = ss.str() + "+"+"3";

            //Sending data to server
            boost::asio::io_service io_service;
            asiotcp::endpoint server_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"), 4000);
            asiotcp::socket socket(io_service);
            socket.open(asiotcp::v4());
            socket.connect(server_endpoint);
            socket.send(boost::asio::buffer(output));

            //Receiving data from Server
            std::array<char, 128> recv_buf;
            size_t const len = socket.receive(boost::asio::buffer(recv_buf));
            std::string const received_message(recv_buf.data(), len);
            std::cout << "received from server: " << received_message << std::endl;

    }

void manageDigiLibBook::markBookBorrowed(){


         std::string mborrow;
         digiLibBook d;

         unsigned int size = myBook.size();

        for(int i=0; i<size; i++){

            std::cout << "Book ISBN " << myBook[i].bookISBN << " " << "\tBook Title: " << myBook[i].bookTitle << std::endl;
        }
            std::cout << std::endl;
            std::cout << "\tSelect ISBN to marked Borrowed: ";
            std::cin>>d.bookISBN;
            std::cout << std::endl;
            std::cout << "\tPress (B) or (b) to Mark this Book as Borrowed: ";
            std::cin >> d.bookBorrowed;
            std::cout << std::endl;
            std::cout << "\t****************************************************" << std::endl;

            std::stringstream ss;
            typedef boost::asio::ip::tcp asiotcp;
            boost::archive::text_oarchive oa{ss};
            oa << d;
            std::string output = ss.str() + "+"+"4";

            //Sending data to server
            boost::asio::io_service io_service;
            asiotcp::endpoint server_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"), 4000);
            asiotcp::socket socket(io_service);
            socket.open(asiotcp::v4());
            socket.connect(server_endpoint);
            socket.send(boost::asio::buffer(output));

            //Receiving data from Server
            std::array<char, 128> recv_buf;
            size_t const len = socket.receive(boost::asio::buffer(recv_buf));
            std::string const received_message(recv_buf.data(), len);
            std::cout << "received from server: " << received_message << std::endl;
}

void manageDigiLibBook::showListOfBorrowedBooks(){


            typedef boost::asio::ip::tcp asiotcp;
            std::stringstream ss;

            boost::archive::text_oarchive oa{ss};
            oa << bObj;

            std::string output = ss.str() + "+" + "5";

            // sending Request
            boost::asio::io_service io_service;
            asiotcp::endpoint server_endpoint = asiotcp::endpoint(boost::asio::ip::address_v4::from_string("127.0.0.1"), 4000);
            asiotcp::socket socket(io_service);
            socket.open(asiotcp::v4());
            socket.connect(server_endpoint);
            socket.send(boost::asio::buffer(output));

            // Receiving Response
            std::array<char, 128> recv_buf;
            size_t const len = socket.receive(boost::asio::buffer(recv_buf));
            //digiLibBook tempObj;
            std::string received_message(recv_buf.data(), len);

                std::stringstream ss1;
                ss1 << received_message;
                boost::archive::text_iarchive oa1{ss1};
                oa1 & myBook;
                std::cout << myBook.size() << std::endl;

                for(int i=0; i<myBook.size(); i++){
                    if(myBook[i].bookBorrowed == "b" || myBook[i].bookBorrowed == "B"){
                        std::cout << "Borrowed Book ISBN " << myBook[i].bookISBN << " " << "\tBook Title: " << myBook[i].bookTitle << std::endl;
                    }
                }

}

