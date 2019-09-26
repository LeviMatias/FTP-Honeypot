//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_CLIENT_PROXY_SERVER_H
#define TP3_CLIENT_PROXY_SERVER_H

#include "common_message.h"
#include <string>
#include "common_proxy.h"

class ProxyServer: Proxy{

public:

    explicit ProxyServer(std::string host, int port);

    void Connect();

private:
    //socket
};


#endif //TP3_CLIENT_PROXY_SERVER_H
