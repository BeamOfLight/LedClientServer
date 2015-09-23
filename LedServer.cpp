#include "LedServer.h" 
  
LedServer::LedServer(boost::asio::io_service& io_service, short port, CommandManager* manager)
	: io_service_(io_service),
      acceptor_(io_service, tcp::endpoint(tcp::v4(), port))
{
	manager_ = manager;
    Session* new_session = new Session(io_service_, manager);
    acceptor_.async_accept(
		new_session->socket(),
        boost::bind(
			&LedServer::handleAccept,
			this,
			new_session,
			boost::asio::placeholders::error
		)
	);
}

void LedServer::handleAccept(Session* new_session, const boost::system::error_code& error)
{
    if (!error) {
		new_session->start();
		new_session = new Session(io_service_, manager_);
		acceptor_.async_accept(
			new_session->socket(),
			boost::bind(&LedServer::handleAccept, this, new_session, boost::asio::placeholders::error)
		);
    } else {
		delete new_session;
    }
  }