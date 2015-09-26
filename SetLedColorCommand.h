#ifndef SET_LED_COLOR_COMMAND_H
#define SET_LED_COLOR_COMMAND_H

#include "AbstractCommand.h"
#include <map>
#include <string>

#define COLOR_RED_TEXT "red"
#define COLOR_GREEN_TEXT "green"
#define COLOR_BLUE_TEXT "blue"

struct SetLedColorCommand : public AbstractCommand
{
    SetLedColorCommand();
    CommandResult* applyCommand(Led* led, std::string argument);
};

#endif
