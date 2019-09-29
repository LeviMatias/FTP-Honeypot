//
// Created by Matias on 29/09/2019.
//

#include "server_quit_cmd.h"

std::vector<Message>
QuitCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message> msgs;
    msgs.emplace_back(conf.Get("quitSuccess"), true);
    return msgs;
}

std::unique_ptr<Command> QuitCmd::Get() {
    return std::unique_ptr<Command>(new QuitCmd);
}
