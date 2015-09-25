#include "SetLedStateCommand.h"

SetLedStateCommand::SetLedStateCommand()
{
    name_ = "set-led-state";
    argument_list_ = {LED_STATE_ON, LED_STATE_OFF};
}

pair < string, bool > SetLedStateCommand::applyCommand(Led* led, string argument)
{
    map <string, unsigned char> reverse_state_map;
    reverse_state_map[LED_STATE_ON] = true;
    reverse_state_map[LED_STATE_OFF] = false;

    set < string> arg_list = getArgumentList();
    auto it = arg_list.find(argument);
    bool status = false;
    if (it != arg_list.end()) {
        status = true;
        led->setState(reverse_state_map[argument]);
    }

    return make_pair("", status);
}
