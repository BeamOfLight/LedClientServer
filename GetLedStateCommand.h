#ifndef GET_LED_STATE_COMMAND_H
#define GET_LED_STATE_COMMAND_H

#include "AbstractCommand.h"

using namespace std;

struct GetLedStateCommand : public AbstractCommand
{
    GetLedStateCommand();
    pair < string, bool > applyCommand(Led* led, string argument);
};

#endif
