#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include "AbstractCommand.h"
#include <map>
#include <string>
#include <iostream>
#include <cstdlib>

#define STATUS_MESSAGE_OK "OK"
#define STATUS_MESSAGE_FAILED "FAILED"

class CommandManager
{
public:
    CommandManager(Led* led);
    bool registerCommand(AbstractCommand* cmd);
    size_t getSize();
    std::string getResponse(std::string request);
    Led* getLed();

private:
    std::map < std::string, AbstractCommand* > registered_commands_;
    Led* led_;
};
#endif
