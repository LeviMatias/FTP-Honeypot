//
// Created by Matias on 28/09/2019.
//

#include "server_mkdir_cmd.h"

std::vector<Message> MakeDirCmd::Execute(SafeSet<std::string> &set, std::string arg) {
    std::vector<Message> msgs;
    if (set.Contains(arg)){
        msgs.emplace_back(Message("550 <mkdFailed>",true));
    } else {
        set.Insert(arg);
        std::string msg = "257 \""+arg+" <mkdSuccess>\"";
        msgs.emplace_back(Message(msg, true));
    }
    return msgs;
}
