//
// Created by Matias on 28/09/2019.
//

#include "server_command.h"

std::vector<Message>
Command::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message>m;
    m.emplace_back(args,true);
    return m;
}

void Command::AssertLogged(UserProfile &user) {
    if (!user.IsLogged()) throw NotLoggedException();
}
