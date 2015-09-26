#include "SetLedRateCommand.h"

SetLedRateCommand::SetLedRateCommand()
{
    name_ = "set-led-rate";
}

CommandResult* SetLedRateCommand::applyCommand(Led* led, std::string argument)
{
    unsigned char rate = atoi(argument.c_str());
    bool status = false;
    if (rate >= 0 && rate <= RATE_MAX) {
        status = true;
        led->setRate(rate);
    }

    return new CommandResult("", status);
}
