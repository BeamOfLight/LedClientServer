#include "SetLedRateCommand.h"

SetLedRateCommand::SetLedRateCommand()
{
    name_ = "set-led-rate";
}

pair < string, bool > SetLedRateCommand::applyCommand(Led* led, string argument)
{
    unsigned char rate = atoi(argument.c_str());
    bool status = false;
    if (rate >= 0 && rate <= RATE_MAX) {
        status = true;
        led->setRate(rate);
    }

    return make_pair("", status);
}
