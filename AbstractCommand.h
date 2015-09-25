#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H

#include <set>
#include <string>
#include "Led.h"

using namespace std;

class AbstractCommand
{
protected:
    string name_;
    set <string> argument_list_;
public:
    AbstractCommand();
    virtual ~AbstractCommand();
    virtual pair < string, bool > applyCommand(Led* led, string argument);

    string name();
    set <string> getArgumentList();
};

#endif
