#ifndef LED_SERVER_H
#define LED_SERVER_H

#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <utility>
#include <ctime>

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/thread.hpp>

#include "AbstractCommand.h"
#include "Session.h"
#include "CommandManager.h"

class LedServer
{
public:
    LedServer(boost::asio::io_service& io_service, short port, CommandManager* manager);
    void handleAccept(Session* new_session, const boost::system::error_code& error);

private:
    CommandManager* manager_;
    boost::asio::io_service& io_service_;
    tcp::acceptor acceptor_;
};
#endif
