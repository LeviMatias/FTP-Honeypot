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
    void Serve(const int service, const std::string &config);

private:
    CmdInterpreter interpreter;
};


#endif //TP3_SERVER_SERVER_H
