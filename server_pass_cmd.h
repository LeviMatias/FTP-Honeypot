//
// Created by Matias on 29/09/2019.
//

#ifndef TP3_SERVER_PASS_CMD_H
#define TP3_SERVER_PASS_CMD_H

#include "server_command.h"

class PassCmd : public Command{
	
	PassCmd() = default;
public:

    std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args) override;

    void AssertLogged(UserProfile &user) override{};

    static std::unique_ptr<Command> Get();
};


#endif //TP3_SERVER_PASS_CMD_H
