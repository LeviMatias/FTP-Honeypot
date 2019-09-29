#include <iostream>

#include "client_client.h"
#include "server_server.h"
int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    Server server("config.cfg");
    server.Serve(8021);
    return 0;
}
