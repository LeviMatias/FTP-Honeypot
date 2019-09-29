//
// Created by Matias on 28/09/2019.
//

#include "server_command_interpreter.h"

std::vector<Message> CmdInterpreter::ExecuteCommand(UserProfile &user,\
                                    const std::string s){
    const auto cmd = s.substr(0, s.find(' '));
    std::vector<Message> msgs;
    try{
        auto len = cmd.length() + 1;
        auto pCmd = cmds.at(cmd)();//returns smart pointer to command
        msgs = pCmd->Execute(this->dirs, user,s.substr(len, s.size()-len));
        user.LogLastCommand(cmd);
    } catch(...) {
        msgs.clear();
        msgs.emplace_back(Message(GetFromConfig("unknownCommand"),true));
    }
    return msgs;
}

void CmdInterpreter::LoadConfig(Config &cfgs) {
    this->configs = &cfgs;
}

std::string CmdInterpreter::GetFromConfig(const std::string s) {
    return this->configs->Get(s);
}

CmdInterpreter::CmdInterpreter() {
    cmds["MKD"] = &MakeDirCmd::Get;
    cmds["LIST"] = &ListCmd::Get;
}
