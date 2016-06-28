#include "manage_User.h"
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

void dumpUser(manage_User const &uOdb)

{
 std::ostream &os = std::cout;
 os << "\n\t******************************************" << std::endl;
 os << "\tUser id   :         " << uOdb.uid<< std::endl;
 os << "\tUser Name :         " << uOdb.uName << std::endl;
 os << "\tUser Email:          " << uOdb.uEmail << std::endl;
 os << "******************************************" << std::endl;

}

manage_User::manage_User()
{
    //ctor
}

manage_User::~manage_User()
{
    //dtor
}

std::string manage_User::addUser(std::string inputmessage){

    manage_User addObj;

    try{
        std::stringstream ss;
        ss << inputmessage;
        boost::archive::text_iarchive ia{ss};
        ia >> addObj;

        userData.push_back(addObj);
        return "User Added";
    }
    catch(std::exception& e){

        std::cerr << e.what() << std::endl;
    }
}

std::string manage_User::showUserList(){

    typedef boost::asio::ip::tcp asiotcp;
    std::stringstream ss;

    boost::archive::text_oarchive oa{ss};
    oa & userData;
    std::string output = ss.str();
    return output;
}

std::string manage_User::updateUser(std::string modUser){

    try{

        manage_User modObj;
        std::stringstream ss;
        ss << modUser;
        boost::archive::text_iarchive ia{ss};
        ia >> modObj;

        for(int i = 0; i < userData.size(); i++){

            if(modObj.uid == userData[i].uid){
                userData.erase(userData.begin()+i);
                userData.push_back(modObj);

                return "User Updated";
            }
        }
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return "User Not Updated";
}
