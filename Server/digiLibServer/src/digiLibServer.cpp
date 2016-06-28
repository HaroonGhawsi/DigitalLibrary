#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/algorithm/string.hpp>
#include "digiLibData.h"
#include "digiLibBook.h"
#include "manage_User.h"


class digiLibServer
{
    public:
        digiLibServer();
        virtual ~digiLibServer();

    protected:
    private:
};

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(){

    try{
        typedef boost::asio::ip::tcp asiotcp;
        boost::asio::io_service io_service;
         digiLibData dbData;
         manage_User muData;
         int static first = 0;

        while(true){

            asiotcp::socket socket(io_service);
            asiotcp::acceptor a(io_service, asiotcp::endpoint(asiotcp::v4(), 4000));
            a.accept(socket);
            std::array<char, 256> recv_buf;
            std::size_t const received_bytes = socket.receive(boost::asio::buffer(recv_buf));
            std::string const token(recv_buf.data(), received_bytes);
            if(first == 0){
                std::cout << "client sent message: \"" << token << "\"" << std::endl;
                first++;
            }

            std::vector<std::string> parts = split(token, '+');

            if(parts.size() == 2){

                    if(parts[1] == "1"){

                        std::string msg = dbData.saveNewBookToMemory(parts[0]);
                        std::cout << msg << std::endl;
                        socket.send(boost::asio::buffer(msg));
                    }else if (parts[1] == "2"){

                        std::string msg = dbData.showAllBooksFromMemory();
                        std::cout << "Show List of books" << std::endl;
                        socket.send(boost::asio::buffer(msg));
                     }else if(parts[1] == "3"){

                            std::string msg = dbData.updateBookInMemory(parts[0]);
                            std::cout << msg << std::endl;
                            socket.send(boost::asio::buffer(msg));
                    }else if(parts[1] == "4"){

                            std::string msg = dbData.markBookBorrowedInMemory(parts[0]);
                            std::cout << msg << std::endl;
                            socket.send(boost::asio::buffer(msg));
                    }else if(parts[1] == "5"){

                        std::string msg = dbData.showAllBorrowedBooksFromMemory();
                        std::cout << "Show All Borrowed Books" << std::endl;
                        socket.send(boost::asio::buffer(msg));
                    }else if(parts[1] == "6"){

                        std::string msg = muData.addUser(parts[0]);
                        std::cout << msg << std::endl;
                        socket.send(boost::asio::buffer(msg));
                    }else if(parts[1] == "7"){

                        std::string msg = muData.showUserList();
                        std::cout << "Show list of Users" << std::endl;
                        socket.send(boost::asio::buffer(msg));
                    }else if(parts[1] == "8"){

                        std::string msg = muData.updateUser(parts[0]);
                        std::cout << msg << std::endl;
                        socket.send(boost::asio::buffer(msg));
                    }
                }
                else{

                    std::string const message = "Hello Digital Library Client. \n";
                    socket.send(boost::asio::buffer(message));
                }
            }
    }catch(std::exception& e){

        std::cerr << e.what() << std::endl;
    }
    return 0;
}
