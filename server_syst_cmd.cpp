//
// Created by Matias on 29/09/2019.
//

#include "server_syst_cmd.h"

std::vector<Message>
SystCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    return Command::Execute(dirs, conf, user,\
                            "215 " + conf.Get("systemInfo"));
}

std::unique_ptr<Command> SystCmd::Get() {
    return std::unique_ptr<Command>(new SystCmd);
}
