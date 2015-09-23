#include "AbstractCommand.h"

AbstractCommand::AbstractCommand()
{
	
}

AbstractCommand::~AbstractCommand()
{
	
}
	
string AbstractCommand::getName()
{
	return name;
}

pair < string, bool > AbstractCommand::applyCommand(Led* led, string argument)
{

}

set <string> AbstractCommand::getArgumentList()
{
	return argument_list;
}

bool AbstractCommand::hasArguments()
{
	return (bool) argument_list.size();
}