//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_COMMAND_H
#define TP3_SERVER_COMMAND_H

#include <vector>
#include <string>
#include <memory>
#include "common_message.h"
#include "safe_set_template.h"
#include "server_config.h"
#include "server_user_profile.h"

class Command {
public:
    virtual std::vector<Message>
    Execute(SafeSet<std::string> &set, UserProfile &user, std::string args);
};


#endif //TP3_SERVER_COMMAND_H
