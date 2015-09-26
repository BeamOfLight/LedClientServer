#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H

#include <set>
#include <string>
#include "Led.h"
#include "CommandResult.h"

class AbstractCommand
{
protected:
    std::string name_;
    set <std::string> argument_list_;
public:
    AbstractCommand();
    virtual ~AbstractCommand();
    virtual CommandResult* applyCommand(Led* led, std::string argument);

    std::string name();
    set <std::string> getArgumentList();
};

#endif
