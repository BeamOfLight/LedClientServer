#include "GetLedStateCommand.h"

GetLedStateCommand::GetLedStateCommand()
{
	name = "get-led-state";
}

GetLedStateCommand::~GetLedStateCommand()
{

}

pair < string, bool > GetLedStateCommand::applyCommand(Led* led, string argument)
{
	string result = "off";
	if (led->getState()) {
		result = "on";
	}

	return make_pair (result, true);
}