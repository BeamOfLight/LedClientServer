#include "AbstractCommand.h"

AbstractCommand::AbstractCommand()
{
}

AbstractCommand::~AbstractCommand()
{

}

string AbstractCommand::name()
{
    return name_;
}

pair < string, bool > AbstractCommand::applyCommand(Led* led, string argument)
{

}

set <string> AbstractCommand::getArgumentList()
{
    return argument_list_;
}
