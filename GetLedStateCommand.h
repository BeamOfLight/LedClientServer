#ifndef GET_LED_STATE_COMMAND_H
#define GET_LED_STATE_COMMAND_H

#include "AbstractCommand.h"

struct GetLedStateCommand : public AbstractCommand
{
    GetLedStateCommand();
    CommandResult* applyCommand(Led* led, std::string argument);
};

#endif
