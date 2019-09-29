//
// Created by Matias on 29/09/2019.
//

#include "server_user_cmd.h"

std::vector <Message>
UserCmd::Execute(SafeSet <std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message> msgs;
    if (user.IsLogged()){
        msgs.emplace_back("100 Already logged",true);
    } else {
        if (!user.IsLogged() && \
                user.GetUser().empty() && args==conf.Get("user")) {
            user.SetUser(args);
        }
        msgs.emplace_back("331 "+conf.Get("passRequired"),true);
    }
    return msgs;
}

std::unique_ptr<Command> UserCmd::Get() {
    return std::unique_ptr<Command>(new UserCmd);
}
