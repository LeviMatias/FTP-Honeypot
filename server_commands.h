//
// Created by Matias on 01/10/2019.
//

#ifndef TP3_SERVER_COMMANDS_H
#define TP3_SERVER_COMMANDS_H

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
//////////////////////////////////////////////////////////

class NotLoggedException : public std::exception{
public:
    NotLoggedException() : std::exception(){};
};
///////////////////// USER ///////////////////////////////

class UserCmd : public Command{
public:
    std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args) override;

    void AssertLogged(UserProfile &user) override{};

    static std::shared_ptr<Command> Get();

 //   template <typename Args>
 //   static std::shared_ptr<Command> Get(Args&& args);
};
/////////////////////// SYST ////////////////////////////////

class SystCmd : public Command{
public:
    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    static std::shared_ptr<Command> Get();
};
/////////////////////// REMOV ///////////////////////////////

class RemovDirCmd : public Command{
public:
    std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args) override;

    static std::shared_ptr<Command> Get();
};
///////////////////////QUIT////////////////////////////

class QuitCmd : public Command{
public:
    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    void AssertLogged(UserProfile &user) override{};

    static std::shared_ptr<Command> Get();
};
///////////////////////PWD////////////////////////////

class PwdCmd : public Command{
public:

    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    static std::shared_ptr<Command> Get();
};
//////////////////////PASS////////////////////////////////

class PassCmd : public Command{
public:

    std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args) override;

    void AssertLogged(UserProfile &user) override{};

    static std::shared_ptr<Command> Get();
};
/////////////////////MAKE/////////////////////////////////

class MakeDirCmd : public Command{
public:

    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    static std::shared_ptr<Command> Get();
};
/////////////////////// HELP ///////////////////////////////

class HelpCmd : public Command{
public:

    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    static std::shared_ptr<Command> Get();
};
/////////////////////// LIST //////////////////////////////

class ListCmd : public Command {
public:

    virtual std::vector<Message>
    Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
            std::string args);

    static std::shared_ptr<Command> Get();
};


#endif //TP3_SERVER_COMMANDS_H
