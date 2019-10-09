//
// Created by Matias on 01/10/2019.
//

#include "server_commands.h"


std::vector<Message>
Command::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message>m;
    m.emplace_back(args,true);
    return m;
}

void Command::AssertLogged(UserProfile &user) {
    if (!user.IsLogged()) throw NotLoggedException();
}


///////////////////////////// SYST ////////////////////////////
std::vector<Message>
SystCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    return Command::Execute(dirs, conf, user,\
                            "215 " + conf.Get("systemInfo"));
}

std::shared_ptr<Command> SystCmd::Get() {
    return std::make_shared<SystCmd>();
}
///////////////////////// USER ////////////////////////////

std::vector <Message>
UserCmd::Execute(SafeSet <std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message> msgs;
    if (user.IsLogged()){
        msgs.emplace_back("100 Already logged",true);
    } else {
        if (user.GetUser().empty() && args==conf.Get("user")) {
            user.SetUser(args);
        }
        msgs.emplace_back("331 "+conf.Get("passRequired"),true);
    }
    return msgs;
}

std::shared_ptr<Command> UserCmd::Get() {
    return std::make_shared<UserCmd>();
}
//////////////////////// HELP /////////////////////////////

std::vector<Message>
HelpCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {

    return Command::Execute(dirs, conf, user, \
    "214 "+conf.Get("commands"));
}

std::shared_ptr<Command> HelpCmd::Get() {
    return std::make_shared<HelpCmd>();
}
/////////////////////// QUIT ///////////////////////////////

std::vector<Message>
QuitCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message> msgs;
    user.Disconnect();
    msgs.emplace_back("221 "+conf.Get("quitSuccess"), true);
    msgs.back().SetConnectionClosed(true);
    return msgs;
}

std::shared_ptr<Command> QuitCmd::Get() {
    return std::make_shared<QuitCmd>();
}
//////////////////////// REMOV ///////////////////////////////

std::vector<Message>
RemovDirCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
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

std::shared_ptr<Command> RemovDirCmd::Get() {
    return std::make_shared<RemovDirCmd>();
}
/////////////////////// MAKE ///////////////////////////////

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

std::shared_ptr<Command> MakeDirCmd::Get() {
    return std::make_shared<MakeDirCmd>();
}
////////////////////// PASS /////////////////////////////////

std::vector<Message>
PassCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message> msgs;
    if (user.IsLogged()){
        msgs.emplace_back("100 Already logged",true);
    } else if (!user.IsLogged() && \
                !user.GetUser().empty() && args==conf.Get("password")){
        msgs.emplace_back("230 "+conf.Get("loginSuccess"),true);
        user.LogUser();
    } else {
        msgs.emplace_back("530 "+conf.Get("loginFailed"),true);
        user.ResetProfile();
    }
    return msgs;
}

std::shared_ptr<Command> PassCmd::Get() {
    return std::make_shared<PassCmd>();
}
/////////////////////// PWD ///////////////////////////////

std::vector<Message>
PwdCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                std::string args) {
    return Command::Execute(dirs, conf, user,\
                            "257 " + conf.Get("currentDirectoryMsg"));
}

std::shared_ptr<Command> PwdCmd::Get() {
    return std::make_shared<PwdCmd>();
}
/////////////////////// LIST ///////////////////////////////

std::vector<Message>
ListCmd::Execute(SafeSet<std::string> &dirs, Config &conf, UserProfile &user,
                 std::string args) {
    std::vector<Message>m;
    std::string hardcoded = "drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 ";

    auto all = dirs.GetAll();
    m.emplace_back("150 " + conf.Get("listBegin"),false);
    std::for_each(all.begin(), all.end(), [&](std::string &s){
        m.emplace_back(hardcoded + s, false);//change
    });
    m.emplace_back("226 " + conf.Get("listEnd"),true);
    return m;
}

std::shared_ptr<Command> ListCmd::Get() {
    return std::make_shared<ListCmd>();
}



