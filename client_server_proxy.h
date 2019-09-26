//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_CLIENT_SERVER_PROXY_H
#define TP3_CLIENT_SERVER_PROXY_H

#include "common_message.h"
#include <string>
#include "common_proxy.h"

class ServerProxy: Proxy{

public:

    explicit ServerProxy(std::string host, int port);

    void Connect();
    
private:
    //socket
};


#endif //TP3_CLIENT_SERVER_PROXY_H
