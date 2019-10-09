//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_CONFIG_H
#define TP3_SERVER_CONFIG_H

#include <string>
#include <map>

class Config {
public:

	//sets the value to the field in config
    void Add(const std::string& field, const std::string &value);

    //returns the value in field in config
    //out of bounds exception if field not found
    std::string Get(const std::string& field) const;

private:
    std::map<std::string, std::string> m;
};


#endif //TP3_SERVER_CONFIG_H
