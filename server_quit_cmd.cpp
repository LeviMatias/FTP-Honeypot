//
// Created by Matias on 29/09/2019.
//

#include "server_quit_cmd.h"

std::vector<Message>
QuitCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message> msgs;
    user.Disconnect();
    msgs.emplace_back("221 "+conf.Get("quitSuccess"), true);
    msgs.back().SetConnectionClosed(true);
    return msgs;
}

std::unique_ptr<Command> QuitCmd::Get() {
    return std::unique_ptr<Command>(new QuitCmd);
}
