//
// Created by Matias on 28/09/2019.
//

#include "server_command_interpreter.h"

std::vector<Message> CmdInterpreter::ExecuteCommand(UserProfile &user,\
                                    const std::string s){
    const auto cmd = s.substr(0, s.find(' '));
    std::vector<Message> msgs;
    try {
        auto pCmd = cmds.at(cmd)();//returns smart pointer to command
        pCmd->AssertLogged(user);
        msgs = pCmd->Execute(this->dirs, *configs, user,\
                s.substr(cmd.length(), s.size() - cmd.length() - 1));
        user.LogLastCommand(cmd);
    } catch (NotLoggedException &e){
        msgs.clear();
        msgs.emplace_back(GetFromConfig("clientNotLogged"),true);
    } catch(std::out_of_range &e) {
        msgs.clear();
        msgs.emplace_back(GetFromConfig("unknownCommand"),true);
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
    cmds["USER"] = &UserCmd::Get;
    cmds["PASS"] = &PassCmd::Get;
    cmds["PWD"] = &PwdCmd::Get;
    cmds["MKD"] = &MakeDirCmd::Get;
    cmds["RMD"] = &RemovDirCmd::Get;
    cmds["SYST"] = &SystCmd::Get;
    cmds["LIST"] = &ListCmd::Get;
    cmds["HELP"] = &HelpCmd::Get;
    cmds["QUIT"] = &QuitCmd::Get;
}
