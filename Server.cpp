#include "Session.h"
#include "LedServer.h"
#include "CommandManager.h"

#include "GetLedStateCommand.h"
#include "SetLedStateCommand.h"
#include "GetLedColorCommand.h"
#include "SetLedColorCommand.h"
#include "GetLedRateCommand.h"
#include "SetLedRateCommand.h"

using boost::asio::ip::tcp;
using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	try {
		if (argc != 2) {
			std::cerr << "Usage: server <port>\n";
			return 1;
		}

		boost::asio::io_service io_service;

		Led* led = new Led();
		cout << led->getInfo() << endl;
		CommandManager* manager = new CommandManager(led);
		manager->registerCommand(new GetLedStateCommand());
		manager->registerCommand(new SetLedStateCommand());
		manager->registerCommand(new GetLedColorCommand());
		manager->registerCommand(new SetLedColorCommand());
		manager->registerCommand(new GetLedRateCommand());
		manager->registerCommand(new SetLedRateCommand());
		cout << "Registered commands count: " << manager->getSize() << endl;
		LedServer led_server = LedServer(io_service, atoi(argv[1]), manager);

		io_service.run();
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
