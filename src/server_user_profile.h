//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_USER_PROFILE_H
#define TP3_SERVER_USER_PROFILE_H

#include <string>

class UserProfile {
public:

    UserProfile();

    //returns set username or "" if no user has been set
    std::string GetUser();

    void SetUser(std::string user);

    //sets user log status to true
    void LogUser();

    bool IsLogged();

    //returns the last command the user successfully issued
    std::string GetLastCommand();

    //stores k as last command issued
    void LogLastCommand(std::string k);

    //resets profile to constructor values (unlogs and connects)
    void ResetProfile();

    //disconnects the user
    void Disconnect();

    bool IsConnected();

private:
    std::string user;
    bool is_logged;
    bool disconnected;
    std::string last_cmd_key;
};


#endif //TP3_SERVER_USER_PROFILE_H
