#ifndef MANAGE_USER_H
#define MANAGE_USER_H


#include "digiLibData.h"
#include "digiLibBook.h"
#include "digiLibData.h"
#include <iostream>
#include <sstream>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/serialization/vector.hpp>

class manage_User
{
    public:
        manage_User();
        virtual ~manage_User();

    std::string uid;
    std::string uName;
    std::string uEmail;

        std::string addUser(std::string);
        std::string updateUser(std::string modUser);
        std::string showUserList();
        //std::string removeUser();


    friend class boost::serialization::access;

    template<typename Archive>

    void serialize(Archive &ar, const unsigned int version){

        ar & uid;
        ar & uName;
        ar & uEmail;

    }

    protected:

    std::vector<manage_User> userData;

    private:
};

#endif // MANAGE_USER_H
