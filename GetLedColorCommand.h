#ifndef GET_LED_COLOR_COMMAND_H
#define GET_LED_COLOR_COMMAND_H

#include "AbstractCommand.h"
#include <map>

struct GetLedColorCommand : public AbstractCommand
{
    GetLedColorCommand();
    CommandResult* applyCommand(Led* led, std::string argument);
};

#endif
