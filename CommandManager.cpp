#include "CommandManager.h"

CommandManager::CommandManager(Led* led)
{
    led_ = led;
}

bool CommandManager::registerCommand(AbstractCommand* cmd)
{
    bool status = false;
    if (registered_commands_.find(cmd->name()) == registered_commands_.end()) {
        registered_commands_[cmd->name()] = cmd;
        status = true;
    }

    return status;
}

size_t CommandManager::getSize()
{
    return registered_commands_.size();
}

Led* CommandManager::getLed()
{
    return led_;
}

string CommandManager::getResponse(string request)
{
    bool status = false;
    std::string result_msg = "";
    if (request.find("\n") == request.size() - 1) {
        int pos = request.find(" ");
        std::string command_name, argument = "";
        if (pos == string::npos) {
            command_name = request.substr(0, request.size() - 1);
        } else {
            command_name = request.substr(0, pos);
            argument = request.substr(pos + 1, request.size() - pos - 2);
        }

        auto it = registered_commands_.find(command_name);
        if (it != registered_commands_.end()) {
            CommandResult* result = registered_commands_[command_name]->applyCommand(led_, argument);
            result_msg = result->text;
            status = result->status;
        }
    }

    std::string status_msg;
    if (status) {
        status_msg = STATUS_MESSAGE_OK;
        if (result_msg.size()) {
            result_msg = " " + result_msg;
        }
    } else {
        status_msg = STATUS_MESSAGE_FAILED;
        result_msg = "";
    }

    return status_msg + result_msg + "\n";
}
