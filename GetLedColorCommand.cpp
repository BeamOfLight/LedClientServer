#include "GetLedColorCommand.h"

GetLedColorCommand::GetLedColorCommand()
{
     name_ = "get-led-color";
}

CommandResult* GetLedColorCommand::applyCommand(Led* led, std::string argument)
{
    std::string color_text;
    map <int, std::string> color_map;
    color_map[COLOR_RED] = "red";
    color_map[COLOR_GREEN] = "green";
    color_map[COLOR_BLUE] = "blue";

    return new CommandResult(color_map[led->getColor()], true);
}
