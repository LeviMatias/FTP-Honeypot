//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_CLIENT_CLIENT_H
#define TP3_CLIENT_CLIENT_H

#include <iostream>
#include "client_proxy_server.h"

class Client {
private:
    ProxyServer server;

public:
    void Start();
};


#endif //TP3_CLIENT_CLIENT_H
