#include "SetLedColorCommand.h"

SetLedColorCommand::SetLedColorCommand()
{
    name_ = "set-led-color";
    argument_list_ = {COLOR_RED_TEXT, COLOR_GREEN_TEXT, COLOR_BLUE_TEXT};
}

CommandResult* SetLedColorCommand::applyCommand(Led* led, std::string argument)
{
    map <std::string, LedColor> reverse_color_map;
    reverse_color_map[COLOR_RED_TEXT] = COLOR_RED;
    reverse_color_map[COLOR_GREEN_TEXT] = COLOR_GREEN;
    reverse_color_map[COLOR_BLUE_TEXT] = COLOR_BLUE;

    set <std::string> arg_list = getArgumentList();
    auto it = arg_list.find(argument);
    bool status = false;
    if (it != arg_list.end()) {
        status = true;
        led->setColor(reverse_color_map[argument]);
    }

    return new CommandResult("", status);
}
