#include <iostream>

#include "client_client.h"
int main()
{
    std::cout<<"Hello, World!"<<std::endl;
    Client client;
    client.Start("localhost", 7777);
    return 0;
}
