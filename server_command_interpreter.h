//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_COMMAND_INTERPRETER_H
#define TP3_SERVER_COMMAND_INTERPRETER_H

#include <map>
#include "server_mkdir_cmd.h"
#include "server_list_cmd.h"

#define EXIT_CMD "QUIT"

class CmdInterpreter{
public:

    CmdInterpreter();

    void LoadConfig(Config &configs);

    std::vector<Message> ExecuteCommand(UserProfile &user, const std::string s);

    std::string GetFromConfig(const std::string s);

private:
    Config* configs{nullptr};
    std::map<std::string, std::unique_ptr<Command> (*)()> cmds;
    SafeSet<std::string> dirs;
};


#endif //TP3_SERVER_COMMAND_INTERPRETER_H
