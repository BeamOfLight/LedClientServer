#ifndef GET_LED_STATE_COMMAND_H
#define GET_LED_STATE_COMMAND_H

#include "AbstractCommand.h"

using namespace std;

class GetLedStateCommand : public AbstractCommand
{
  public:
	GetLedStateCommand();
	~GetLedStateCommand();
	
	pair < string, bool > applyCommand(Led* led, string argument);
};

#endif