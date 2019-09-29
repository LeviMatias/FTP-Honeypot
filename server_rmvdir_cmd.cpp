//
// Created by Matias on 29/09/2019.
//

#include "server_rmvdir_cmd.h"

std::vector<Message>
RemvDirCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                    std::string args) {
    std::vector<Message> msgs;
    if (!dirs.Contains(args)){
        msgs.emplace_back("550 " + conf.Get("rmdFailed"),true);
    } else {
        dirs.Erase(args);
        std::string msg = "250 \""+args+"\" " + conf.Get("rmdSuccess");
        msgs.emplace_back(msg, true);
    }
    return msgs;
}

std::unique_ptr<Command> RemvDirCmd::Get() {
    return std::unique_ptr<Command>(new RemvDirCmd);
}
