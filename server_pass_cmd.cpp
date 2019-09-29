//
// Created by Matias on 29/09/2019.
//

#include "server_pass_cmd.h"

std::vector<Message>
PassCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message> msgs;
    if (user.IsLogged()){
        msgs.emplace_back("100 Already logged",true);
    } else if (!user.IsLogged() && \
                !user.GetUser().empty() && args==conf.Get("password")){
        msgs.emplace_back("230 "+conf.Get("loginSuccess"),true);
        user.LogUser();
    } else {
        msgs.emplace_back("530 "+conf.Get("loginFailed"),true);
        user.ResetProfile();
    }
    return msgs;
}

std::unique_ptr<Command> PassCmd::Get() {
    return std::unique_ptr<Command>(new PassCmd);
}
