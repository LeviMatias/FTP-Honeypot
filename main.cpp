#include <iostream>

#include "client_client.h"
#include "server_server.h"
int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    Server server;
    server.Serve(8021, "config.cfg");
    return 0;
}
