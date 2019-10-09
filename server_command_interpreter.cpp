//
// Created by Matias on 28/09/2019.
//

#include "server_command_interpreter.h"

std::vector<Message> CmdInterpreter::ExecuteCommand(UserProfile &user,\
                                    const std::string s){
    const auto cmd = s.substr(0, s.find(' '));
    const std::string arg = (cmd==s) ? \
                "" : s.substr(cmd.length()+1, s.size()-cmd.length()-1);
    std::vector<Message> msgs;
    try {
        std::shared_ptr<Command> pCmd = cmds.at(cmd)();
        pCmd->AssertLogged(user);
        msgs = pCmd->Execute(this->dirs, *configs, user, arg);
        user.LogLastCommand(cmd);
    } catch (NotLoggedException &e){
        msgs.clear();
        msgs.emplace_back("530 "+GetFromConfig("clientNotLogged"),true);
    } catch(std::out_of_range &e) {
        msgs.clear();
        msgs.emplace_back("530 "+GetFromConfig("unknownCommand"),true);
    }
    return msgs;
}

void CmdInterpreter::LoadConfig(Config &cfgs) {
    this->configs = &cfgs;
}

std::string CmdInterpreter::GetFromConfig(const std::string &s) {
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
