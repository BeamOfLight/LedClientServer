#include "GetLedRateCommand.h"

GetLedRateCommand::GetLedRateCommand()
{
    name_ = "get-led-rate";
}

CommandResult* GetLedRateCommand::applyCommand(Led* led, std::string argument)
{
    int param = led->getRate();
    std::stringstream ss;
    ss << param;
    std::string result = ss.str();

    return new CommandResult(result, true);
}
