#ifndef GET_LED_RATE_COMMAND_H
#define GET_LED_RATE_COMMAND_H

#include "AbstractCommand.h"
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

struct GetLedRateCommand : public AbstractCommand
{
    GetLedRateCommand();
    CommandResult* applyCommand(Led* led, std::string argument);
};

#endif
