//
// Created by Matias on 28/09/2019.
//

#include "server_list_cmd.h"

std::vector<Message>
ListCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message>m;
    std::string hardcoded = "drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 ";

    auto all = dirs.GetAll();
    m.emplace_back("150 " + conf.Get("listBegin"),false);
    std::for_each(all.begin(), all.end(), [&](std::string &s){
       m.emplace_back(hardcoded + s, false);//change
    });
    m.emplace_back("226 " + conf.Get("listEnd"),true);
    return m;
}

std::unique_ptr<Command> ListCmd::Get() {
    return std::unique_ptr<Command>(new ListCmd());
}
