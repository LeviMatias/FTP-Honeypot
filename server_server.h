//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SERVER_SERVER_H
#define TP3_SERVER_SERVER_H

#include <iostream>
#include <fstream>
#include "server_command_interpreter.h"
#include "server_acceptor_thread.h"

class Server {
public:
	//creates a server that loads config from passed path
    explicit Server(const std::string &path);

    //begins serving in specified port/service
    void Serve(const int service);

private:
    CmdInterpreter interpreter;
    Config config;

    void ReadConfig(const std::string &config_name);

    void Run(const int service);
};


#endif //TP3_SERVER_SERVER_H
