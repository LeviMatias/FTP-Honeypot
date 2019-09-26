//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SERVER_COMMAND_INTERPRETER_H
#define TP3_SERVER_COMMAND_INTERPRETER_H

#include "common_command.h"
#include <string>
#include <map>

class CommandInterpreter {
private:
    std::map<std::string, common_command> cmd_map;
};


#endif //TP3_SERVER_COMMAND_INTERPRETER_H
