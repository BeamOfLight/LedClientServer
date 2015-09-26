#ifndef SET_LED_RATE_COMMAND_H
#define SET_LED_RATE_COMMAND_H

#include "AbstractCommand.h"
#include <string>
#include <cstdlib>     /* atoi */

#define RATE_MAX 5

struct SetLedRateCommand : public AbstractCommand
{
    SetLedRateCommand();
    CommandResult* applyCommand(Led* led, std::string argument);
};

#endif
