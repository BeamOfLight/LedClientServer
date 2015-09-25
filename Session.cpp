#include "Session.h"

Session::Session(boost::asio::io_service& io_service, CommandManager* manager)
    : socket_(io_service)
{
    manager_ = manager;
}

tcp::socket& Session::socket()
{
    return socket_;
}

void Session::start()
{
    cout << "Session start" << endl;
    socket_.async_read_some(
        boost::asio::buffer(data_, max_length),
        boost::bind(
            &Session::handleRead,
            this,
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred
        )
    );
}

void Session::handleRead(const boost::system::error_code& error, size_t bytes_transferred)
{
    string request = string(data_);
    request = request.substr(0, request.find("\n") + 1);
    string response = manager_->getResponse(request);

    cout << manager_->getLed()->getInfo() << endl;

    if (!error) {
        boost::asio::async_write(
            socket_,
            boost::asio::buffer(response.c_str(), response.size()),
            boost::bind(
                &Session::handleWrite,
                this,
                boost::asio::placeholders::error
            )
        );
    } else {
        delete this;
    }
}

void Session::handleWrite(const boost::system::error_code& error)
{
    if (!error) {
        socket_.async_read_some(
            boost::asio::buffer(data_, max_length),
            boost::bind(
                &Session::handleRead,
                this,
                boost::asio::placeholders::error,
                boost::asio::placeholders::bytes_transferred
            )
        );
    } else {
        delete this;
    }
}
