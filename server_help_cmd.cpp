//
// Created by Matias on 29/09/2019.
//

#include "server_help_cmd.h"

std::vector<Message>
HelpCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {

    return Command::Execute(dirs, conf, user, \
    conf.Get("commands"));
}

std::unique_ptr<Command> HelpCmd::Get() {
    return std::unique_ptr<Command>(new HelpCmd);
}
