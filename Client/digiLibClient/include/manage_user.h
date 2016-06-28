#ifndef MANAGE_USER_H
#define MANAGE_USER_H


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <sstream>
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>


class manage_user
{
    public:
        manage_user();
        virtual ~manage_user();

        std::string uid;
        std::string uName;
        std::string uEmail;

        void addUser();
        void updateUser();
        void showUserList();
        void removeUser();

        friend class boost::serialization::access;

        template<class Archive>

        void serialize(Archive & ar, const unsigned int version){

        ar & uid;
        ar & uName;
        ar & uEmail;

    }
    protected:

        std::vector<manage_user> mUser;

    private:

};

#endif // MANAGE_USER_H
