#include "GetLedColorCommand.h"

GetLedColorCommand::GetLedColorCommand()
{
     name_ = "get-led-color";
}

pair < string, bool > GetLedColorCommand::applyCommand(Led* led, string argument)
{
    string color_text;
    map <int, string> color_map;
    color_map[COLOR_RED] = "red";
    color_map[COLOR_GREEN] = "green";
    color_map[COLOR_BLUE] = "blue";

    return make_pair(color_map[led->getColor()], true);
}
