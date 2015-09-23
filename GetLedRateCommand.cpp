#include "GetLedRateCommand.h"

GetLedRateCommand::GetLedRateCommand()
{
	name = "get-led-rate";
}

GetLedRateCommand::~GetLedRateCommand()
{

}

pair < string, bool > GetLedRateCommand::applyCommand(Led* led, string argument)
{
	int param = led->getRate();
	stringstream ss;
	ss << param;
	string result = ss.str();
	
	return make_pair(result, true);
}