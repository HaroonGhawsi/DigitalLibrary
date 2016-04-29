#ifndef DIGILIBCLIENT_H
#define DIGILIBCLIENT_H

#include <cstdlib>
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <string>
#include <sstream>
#include "digiLibBook.h"
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;



class digiLibClient
{
    public:
        digiLibClient();
        virtual ~digiLibClient();


    protected:
    private:
};

#endif // DIGILIBCLIENT_H
