//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_COMMAND_INTERPRETER_H
#define TP3_SERVER_COMMAND_INTERPRETER_H

#include <map>
#include "server_mkdir_cmd.h"
#include "server_list_cmd.h"
#include "server_user_cmd.h"
#include "server_pass_cmd.h"
#include "server_pwd_cmd.h"
#include "server_rmvdir_cmd.h"
#include "server_help_cmd.h"
#include "server_quit_cmd.h"
#include "server_syst_cmd.h"

#define EXIT_CMD "QUIT"

class CmdInterpreter{
public:

	//creates a new empty interpreter with no set config
    CmdInterpreter();

    //loads the configuration the commands are going to use
    void LoadConfig(Config &configs);

    //PRE Config must have been loaded
    //POS executes the command encased in string for the UserProfile user
    //returns a vector with messages resulting from the attempted execution
    std::vector<Message> ExecuteCommand(UserProfile &user, const std::string s);

    //PRE Config must have been loaded
    //POS returns config string associated with string field
    std::string GetFromConfig(const std::string s);

private:
    Config* configs{nullptr};
    std::map<std::string, std::unique_ptr<Command> (*)()> cmds;
    SafeSet<std::string> dirs;
};


#endif //TP3_SERVER_COMMAND_INTERPRETER_H
