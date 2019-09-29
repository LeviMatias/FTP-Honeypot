//
// Created by Matias on 28/09/2019.
//

#include "server_mkdir_cmd.h"

std::vector<Message>
MakeDirCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                    std::string arg) {
    std::vector<Message> msgs;
    if (dirs.Contains(arg)){
        msgs.emplace_back("550 " + conf.Get("mkdFailed"),true);
    } else {
        dirs.Insert(arg);
        std::string msg = "257 \""+arg+"\" " + conf.Get("mkdSuccess");
        msgs.emplace_back(msg, true);
    }
    return msgs;
}

std::unique_ptr<Command> MakeDirCmd::Get() {
    return std::unique_ptr<Command>(new MakeDirCmd);
}
