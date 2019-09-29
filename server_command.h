//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_COMMAND_H
#define TP3_SERVER_COMMAND_H

#include <vector>
#include <string>
#include <memory>
#include <exception>
#include "common_message.h"
#include "safe_set_template.h"
#include "server_config.h"
#include "server_user_profile.h"

class Command {
public:
    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    virtual void AssertLogged(UserProfile &user);
};

class NotLoggedException : public std::exception{
public:
    NotLoggedException() : std::exception(){};
};

#endif //TP3_SERVER_COMMAND_H
