#ifndef GET_LED_COLOR_COMMAND_H
#define GET_LED_COLOR_COMMAND_H

#include "AbstractCommand.h"
#include <map>

using namespace std;

struct GetLedColorCommand : public AbstractCommand
{
    GetLedColorCommand();
    pair < string, bool > applyCommand(Led* led, string argument);
};

#endif
