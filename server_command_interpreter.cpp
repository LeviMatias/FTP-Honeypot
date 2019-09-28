//
// Created by Matias on 28/09/2019.
//

#include "server_command_interpreter.h"

std::vector<Message> CmdInterpreter::ExecuteCommand(const std::string s){
    const auto cmd = s.substr(0, s.find(' '));
    try{
        auto len = cmd.length() + 1;
        return cmds.at(cmd)->Execute(this->dirs,\
                s.substr(len, s.size()-len));
    } catch(std::out_of_range &e) {
        std::vector<Message> msgs; //TODO ADD INVALID_CMD_CMD
        msgs.emplace_back(Message("INVALIDCOMMAND",true));
        return msgs;
    }
}

void CmdInterpreter::AddCommand(std::string key, Command *cmd) {
    cmds[key] = cmd;
}
