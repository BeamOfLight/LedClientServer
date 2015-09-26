#ifndef SET_LED_STATE_COMMAND_H
#define SET_LED_STATE_COMMAND_H

#include "AbstractCommand.h"
#include <map>
#include <string>

#define LED_STATE_ON "on"
#define LED_STATE_OFF "off"

struct SetLedStateCommand : public AbstractCommand
{
    SetLedStateCommand();
    CommandResult* applyCommand(Led* led, std::string argument);
};

#endif
