//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_USER_PROFILE_H
#define TP3_SERVER_USER_PROFILE_H

#include <string>

class UserProfile {
public:

    UserProfile();

    std::string GetUser();

    void SetUser(std::string user);

    void LogUser();

    bool IsLogged();

    std::string GetLastCommand();

    void LogLastCommand(std::string k);

    void ResetProfile();

    void Disconnect();

    bool IsConnected();

private:
    std::string user;
    bool is_logged;
    bool disconnected;
    std::string last_cmd_key;
};


#endif //TP3_SERVER_USER_PROFILE_H
