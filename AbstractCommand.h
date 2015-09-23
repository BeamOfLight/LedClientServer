#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H

#include <set>
#include <string>
#include "Led.h"

using namespace std;

class AbstractCommand
{
  protected:
	string name;
	set <string> argument_list;
  public:
	AbstractCommand();
	virtual ~AbstractCommand();
	virtual pair < string, bool > applyCommand(Led* led, string argument);
	
	string getName();
	set <string> getArgumentList();
	bool hasArguments();
};

#endif