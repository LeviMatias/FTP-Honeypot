//
// Created by Matias on 28/09/2019.
//

#include "server_user_profile.h"

std::string UserProfile::GetUser() {
    return this->user;
}

void UserProfile::SetUser(std::string usr) {
    this->user = usr;
}

void UserProfile::LogUser() {
    this->is_logged = true;
}

bool UserProfile::IsLogged() {
    return this->is_logged;
}

std::string UserProfile::GetLastCommand() {
    return this->last_cmd_key;
}

void UserProfile::LogLastCommand(std::string k) {
    this->last_cmd_key = k;
}

void UserProfile::ResetProfile() {
    this->last_cmd_key = "";
    this->user = "";
    this->is_logged = false;
}
