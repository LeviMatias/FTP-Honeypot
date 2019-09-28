//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_COMMAND_INTERPRETER_H
#define TP3_SERVER_COMMAND_INTERPRETER_H

#include <map>
#include "server_command.h"
#include "server_mkdir_cmd.h"
#include "server_list_cmd.h"

class CmdInterpreter{
public:

    void AddCommand(std::string key, Command* cmd);

    std::vector<Message> ExecuteCommand(const std::string s);

private:
    std::map<std::string, Command*> cmds;
    SafeSet<std::string> dirs;
    //map <user,pass>
};


#endif //TP3_SERVER_COMMAND_INTERPRETER_H
