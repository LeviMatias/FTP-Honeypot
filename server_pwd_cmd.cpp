//
// Created by Matias on 29/09/2019.
//

#include "server_pwd_cmd.h"

std::vector<Message>
PwdCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                std::string args) {
    return Command::Execute(dirs, conf, user,\
                            "257" + conf.Get("currentDirectoryMsg"));
}

std::unique_ptr<Command> PwdCmd::Get() {
    return std::unique_ptr<Command>(new PwdCmd);
}
