//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SERVER_SERVER_H
#define TP3_SERVER_SERVER_H

#include <iostream>
#include <fstream>
#include "server_command_interpreter.h"

class server_server {
public:
    void Serve(const std::string &config);

private:
    CmdInterpreter interpreter;
};


#endif //TP3_SERVER_SERVER_H
