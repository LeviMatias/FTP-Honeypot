//
// Created by Matias on 28/09/2019.
//

#include "server_list_cmd.h"

std::vector<Message>
ListCmd::Execute(SafeSet<std::string> &set, std::string args) {
    std::vector<Message>m;
    auto all = set.GetAll();
    std::for_each(all.begin(), all.end(), [&](std::string &s){
       m.emplace_back(s, s==all.back());//change
    });
    return m;
}
