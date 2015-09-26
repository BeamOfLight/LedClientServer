#ifndef COMMAND_RESULT_H
#define COMMAND_RESULT_H

#include <string>

struct CommandResult
{
    std::string text;
    bool status;

    CommandResult(std::string new_text, bool new_status) : text(new_text), status(new_status) {};
};

#endif
