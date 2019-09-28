//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_CONFIG_H
#define TP3_SERVER_CONFIG_H

#include <string>
#include <map>

class Config {
public:

    void Add(const std::string&, std::string);

    std::string Get(const std::string&);

private:
    std::map<std::string, std::string> m;
};


#endif //TP3_SERVER_CONFIG_H
