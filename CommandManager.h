#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include "AbstractCommand.h"
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>

#define STATUS_MESSAGE_OK "OK"
#define STATUS_MESSAGE_FAILED "FAILED"

using namespace std;

class CommandManager
{
public:
	CommandManager(Led* led);
    bool registerCommand(AbstractCommand* cmd);
	size_t getSize();
	string getResponse(string request);
	Led* getLed();
	
private:
	map < string, AbstractCommand* > registered_commands_;
	Led* led_;
};
#endif