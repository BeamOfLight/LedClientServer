#include "GetLedStateCommand.h"

GetLedStateCommand::GetLedStateCommand()
{
    name_ = "get-led-state";
}

CommandResult* GetLedStateCommand::applyCommand(Led* led, std::string argument)
{
    string result = "off";
    if (led->getState()) {
        result = "on";
    }

    return new CommandResult(result, true);
}
