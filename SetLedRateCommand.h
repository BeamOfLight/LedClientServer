#ifndef SET_LED_RATE_COMMAND_H
#define SET_LED_RATE_COMMAND_H

#include "AbstractCommand.h"
#include <string>
#include <cstdlib>     /* atoi */

#define RATE_MAX 5

using namespace std;

struct SetLedRateCommand : public AbstractCommand
{
    SetLedRateCommand();
    pair < string, bool > applyCommand(Led* led, string argument);
};

#endif
