//
// Created by Matias on 28/09/2019.
//

#include "server_config.h"

#include <utility>

std::string Config::Get(const std::string& key) const{
    return m.at(key);
}

void Config::Add(const std::string& key, const std::string &value) {
    m[key] = value;
}
