#include <iostream>
#include <string>
#include <memory>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "digiLibData.h"
#include "digiLibBook.h"




class digiLibServer
{
    public:
        digiLibServer();
        virtual ~digiLibServer();

    protected:
    private:
};

int main(){


    try{
        typedef boost::asio::ip::tcp asiotcp;
        boost::asio::io_service io_service;

        while(true){

            asiotcp::socket socket(io_service);
            asiotcp::acceptor a(io_service, asiotcp::endpoint(asiotcp::v4(), 4000));
            a.accept(socket);
            std::array<char, 256> recv_buf;
            std::size_t const received_bytes = socket.receive(boost::asio::buffer(recv_buf));
            std::string const inputmessage(recv_buf.data(), received_bytes);
            std::cout << "client sent message: \"" << inputmessage << "\"" << std::endl;

            digiLibData dbData;
            dbData.saveNewBookToMemory(inputmessage);
            //dbData.showAllBooksFromMemory();
            //std::cout << "Server Testing" << inputmessage << std::endl;

            dbData.showAllBooksFromMemory();

            std::string const message = "Hello Digital Library Client. \n";
            socket.send(boost::asio::buffer(message));

            }
        }

    catch(std::exception& e){

        std::cerr << e.what() << std::endl;
    }
    return 0;
}

