#ifndef SESSION_H
#define SESSION_H

#include <cstdlib>
#include <iostream>
#include <utility>
#include "CommandManager.h"
#include <string>

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>

#include "GetLedStateCommand.h"
#include "SetLedStateCommand.h"
#include "GetLedColorCommand.h"
#include "SetLedColorCommand.h"
#include "GetLedRateCommand.h"
#include "SetLedRateCommand.h"

using boost::asio::ip::tcp;
using namespace std;

class Session
{
public:
    Session(boost::asio::io_service& io_service, CommandManager* manager);
    tcp::socket& socket();
    void start();
    void handleRead(const boost::system::error_code& error, size_t bytes_transferred);
    void handleWrite(const boost::system::error_code& error);

private:
    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
    CommandManager* manager_;
};

#endif
