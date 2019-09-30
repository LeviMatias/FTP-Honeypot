//
// Created by Matias on 29/09/2019.
//

#ifndef TP3_SERVER_USER_CMD_H
#define TP3_SERVER_USER_CMD_H

#include "server_command.h"

class UserCmd : public Command{
private:
    UserCmd() = default;
public:

    std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args) override;

    void AssertLogged(UserProfile &user) override{};

    static std::unique_ptr<Command> Get();
};


#endif //TP3_SERVER_USER_CMD_H
