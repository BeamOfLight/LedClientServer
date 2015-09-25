#ifndef SET_LED_STATE_COMMAND_H
#define SET_LED_STATE_COMMAND_H

#include "AbstractCommand.h"
#include <map>
#include <string>

#define LED_STATE_ON "on"
#define LED_STATE_OFF "off"

using namespace std;

struct SetLedStateCommand : public AbstractCommand
{
    SetLedStateCommand();
    pair < string, bool > applyCommand(Led* led, string argument);
};

#endif
