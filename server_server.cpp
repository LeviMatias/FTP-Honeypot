//
// Created by Matias on 26/09/2019.
//

#include "server_server.h"

Config MakeConfig(const std::string& config_name){
    Config c;
    std::ifstream file;
    file.open(config_name, std::ios::in);
    if (!file.good()) throw std::runtime_error("error opening file");

    std::string line;
    while (getline(file, line) && !file.eof()){
        const auto conf = line.substr(0, line.find('='));
        auto l = conf.length() + 1;
        c.Add(line.substr(l, line.length() - l));
    }
    return c;
}

void server_server::Serve(const std::string& config_name){
    Config config = MakeConfig(config_name);
    MakeDirCmd mkd = MakeDirCmd();
    ListCmd list;//TODO READ CONFIG AND MAKE STATIC CMD EXEC (or not)
    interpreter.AddCommand("MKD", &mkd);
    interpreter.AddCommand("LIST", &list);
}
