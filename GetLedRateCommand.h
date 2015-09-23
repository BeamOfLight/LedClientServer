#ifndef GET_LED_RATE_COMMAND_H
#define GET_LED_RATE_COMMAND_H

#include "AbstractCommand.h"
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class GetLedRateCommand : public AbstractCommand
{
  public:
	GetLedRateCommand();
	~GetLedRateCommand();
	
	pair < string, bool > applyCommand(Led* led, string argument);
};

#endif