//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SERVER_SERVER_H
#define TP3_SERVER_SERVER_H

#include "server_command_interpreter.h"

class server_server {
public:
    void Serve();

private:
    CmdInterpreter interpreter;
};


#endif //TP3_SERVER_SERVER_H
