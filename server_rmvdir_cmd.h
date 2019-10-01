//
// Created by Matias on 29/09/2019.
//

#ifndef TP3_SERVER_RMVDIR_CMD_H
#define TP3_SERVER_RMVDIR_CMD_H

#include "server_command.h"

class RemovDirCmd : public Command{
	RemovDirCmd() = default;
public:

    std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args) override;

    static std::unique_ptr<Command> Get();
};


#endif //TP3_SERVER_RMVDIR_CMD_H
