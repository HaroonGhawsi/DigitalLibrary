#include "manage_user.h"

manage_user::manage_user()
{

}

manage_user::~manage_user()
{
    //dtor
}

void dumpUser(manage_user const &uOdb)

{
 std::ostream &os = std::cout;
 os << "\n\t******************************************" << std::endl;
 os << "\tUser id   :         " << uOdb.uid<< std::endl;
 os << "\tUser Name :         " << uOdb.uName << std::endl;
 os << "\tUser Email:          " << uOdb.uEmail << std::endl;
 os << "******************************************" << std::endl;

}

void manage_user::addUser(){

    manage_user uObj;

    std::stringstream ss;
    typedef boost::asio::ip::tcp asiotcp;

    //Print book details and get the user input

    std::cout << "\n\n\t------------Add New Library User------------";
	std::cout << "\n\tUser id:              ";
	std::cin.ignore();
	getline(std::cin, uObj.uid);
	std::cout << "\tUser Name:              ";
	getline(std::cin, uObj.uName);
	std::cout << "\tUser Email:              ";
	getline(std::cin, uObj.uEmail);

    //Save the input to the myBook vector
	//myBook.push_back(bObj);
    boost::archive::text_oarchive oa{ss};
    oa << uObj;
    //std::cout << "Serialized the book ";
    std::string output = ss.str() + "+"+"6";

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
    std::cout << "\n\t" << "received from server: " << received_message << std::endl;
}

void manage_user::showUserList(){

    typedef boost::asio::ip::tcp asiotcp;
    std::stringstream ss;

    manage_user sUserObj;


    mUser.clear();
    boost::archive::text_oarchive oa{ss};
    oa << sUserObj;


    std::string output = ss.str() + "+"+"7";

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

    std::string received_message(recv_buf.data(), len);

        std::stringstream ss1;
        ss1 << received_message;
        boost::archive::text_iarchive oa1{ss1};
        oa1 & mUser;
        //std::cout << myBook.size() << std::endl;

        for(int i=0;i<mUser.size();i++){
            dumpUser(mUser[i]);
        }
}

void manage_user::updateUser(){

    manage_user mod_User;

    unsigned int size = mUser.size();

    int srNo;

        //iterating through vector and displaying each item of each element of the vector
        for(int i=0; i<size; i++){
            std::cout << "\t" << i << " " << "\tUser Name:        " << mUser[i].uName<< std::endl;
        }
            //Getting input from user to modify the vector element.
            std::cout << std::endl;
            std::cout << "\tSelect a User to modify: ";
            std::cin>>srNo;
            std::cout << "\tUser id:           ";
            std::cin.ignore();
            getline(std::cin, mod_User.uid);
            std::cout << "\tUser Name:         ";
            //std::cin.ignore();
            getline(std::cin, mod_User.uName);
            std::cout << "\tUser Email:        ";
            getline(std::cin, mod_User.uEmail);
            std::cout << "\tYou have successfully modified User No. " << srNo << std::endl;
            std::cout << std::endl;
            std::cout << "\t****************************************************\n\n" << std::endl;

            std::stringstream ss;
            typedef boost::asio::ip::tcp asiotcp;
            boost::archive::text_oarchive oa{ss};
            oa << mUser;
            std::string output = ss.str() + "+"+"8";

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
            std::cout << "\t" << "\n\treceived from server: " << received_message << std::endl;

    }


