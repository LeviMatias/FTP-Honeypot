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
protected:
	//TRAIT
	//All derived classes must implement a static method 
	//Get that returns a smart pointer to a "new <derived class>"
	
	Command()=default;
public:
    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    //PRE method is not overriden, overriden methods usually dont follow the POS
    //POS Asserts whether the user is logged or not
    //throws NotLoggedException when false
    virtual void AssertLogged(UserProfile &user);
};

class NotLoggedException : public std::exception{
public:
    NotLoggedException() : std::exception(){};
};

#endif //TP3_SERVER_COMMAND_H
