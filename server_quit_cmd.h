//
// Created by Matias on 29/09/2019.
//

#ifndef TP3_SERVER_QUIT_CMD_H
#define TP3_SERVER_QUIT_CMD_H


#include "server_command.h"

class QuitCmd : public Command{
public:

    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    static std::unique_ptr<Command> Get();
};

#endif //TP3_SERVER_QUIT_CMD_H
