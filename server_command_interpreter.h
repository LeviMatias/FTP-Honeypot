//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_COMMAND_INTERPRETER_H
#define TP3_SERVER_COMMAND_INTERPRETER_H

#include <map>
#include "server_commands.h"


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
    std::string GetFromConfig(const std::string &s);

private:
    Config* configs{nullptr};
    std::map<std::string, std::shared_ptr<Command> (*)()> cmds;
    SafeSet<std::string> dirs;
};


#endif //TP3_SERVER_COMMAND_INTERPRETER_H
