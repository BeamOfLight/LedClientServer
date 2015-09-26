#include "AbstractCommand.h"

AbstractCommand::AbstractCommand()
{
}

AbstractCommand::~AbstractCommand()
{

}

std::string AbstractCommand::name()
{
    return name_;
}

CommandResult* AbstractCommand::applyCommand(Led* led, std::string argument)
{

}

set <std::string> AbstractCommand::getArgumentList()
{
    return argument_list_;
}
