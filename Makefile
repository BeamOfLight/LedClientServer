all: Client Server

Client: Client.o Session.o Led.o CommandManager.o LedServer.o AbstractCommand.o GetLedStateCommand.o SetLedStateCommand.o GetLedColorCommand.o SetLedColorCommand.o GetLedRateCommand.o SetLedRateCommand.o
	g++ -std=c++11 -o client Client.o Session.o Led.o CommandManager.o LedServer.o AbstractCommand.o GetLedStateCommand.o SetLedStateCommand.o GetLedColorCommand.o SetLedColorCommand.o GetLedRateCommand.o SetLedRateCommand.o -lboost_system -lboost_thread -lpthread
	
Client.o: Client.cpp
	g++ -std=c++11 -c Client.cpp

Server: Server.o Session.o Led.o CommandManager.o LedServer.o AbstractCommand.o GetLedStateCommand.o SetLedStateCommand.o GetLedColorCommand.o SetLedColorCommand.o GetLedRateCommand.o SetLedRateCommand.o
	g++ -std=c++11 -o server Server.o Session.o Led.o CommandManager.o LedServer.o AbstractCommand.o GetLedStateCommand.o SetLedStateCommand.o GetLedColorCommand.o SetLedColorCommand.o GetLedRateCommand.o SetLedRateCommand.o -lboost_system -lboost_thread
	
Server.o: Server.cpp
	g++ -std=c++11 -c Server.cpp
	
Led.o: Led.cpp
	g++ -std=c++11 -c Led.cpp
	
CommandManager.o: CommandManager.cpp
	g++ -std=c++11 -c CommandManager.cpp
	
Session.o: Session.cpp
	g++ -std=c++11 -c Session.cpp

LedServer.o: LedServer.cpp
	g++ -std=c++11 -c LedServer.cpp
	
AbstractCommand.o: AbstractCommand.cpp
	g++ -std=c++11 -c AbstractCommand.cpp
	
GetLedStateCommand.o: GetLedStateCommand.cpp
	g++ -std=c++11 -c GetLedStateCommand.cpp
	
SetLedStateCommand.o: SetLedStateCommand.cpp
	g++ -std=c++11 -c SetLedStateCommand.cpp
	
GetLedColorCommand.o: GetLedColorCommand.cpp
	g++ -std=c++11 -c GetLedColorCommand.cpp
	
SetLedColorCommand.o: SetLedColorCommand.cpp
	g++ -std=c++11 -c SetLedColorCommand.cpp
	
GetLedRateCommand.o: GetLedRateCommand.cpp
	g++ -std=c++11 -c GetLedRateCommand.cpp
	
SetLedRateCommand.o: SetLedRateCommand.cpp
	g++ -std=c++11 -c SetLedRateCommand.cpp

clean: 
	rm -f *.o 
