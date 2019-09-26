//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_CLIENT_CLIENT_H
#define TP3_CLIENT_CLIENT_H

#include <iostream>
#include "client_server_proxy.h"

class Client {
private:
    ServerProxy server;

public:
    void start();
};


#endif //TP3_CLIENT_CLIENT_H
