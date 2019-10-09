//
// Created by Matias on 28/09/2019.
//

#include "server_config.h"

#include <utility>

std::string Config::Get(const std::string& key) {
    return m.at(key);
}

void Config::Add(const std::string& key, std::string value) {
    m[key] = std::move(value);
}
