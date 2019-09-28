//
// Created by Matias on 28/09/2019.
//

#include "server_list_cmd.h"

std::vector<Message>
ListCmd::Execute(SafeSet<std::string> &set, std::string args) {
    std::vector<Message>m;
    std::string hardcoded = "drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 ";

    auto all = set.GetAll();
    std::for_each(all.begin(), all.end(), [&](std::string &s){
       m.emplace_back(hardcoded + s, s==all.back());//change
    });
    return m;
}
