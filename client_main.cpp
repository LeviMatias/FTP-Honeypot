//
// Created by Matias on 29/09/2019.
//

#include "client_client.h"
int main__(int argc, char** argv)
{
    try {
        Client client;
        client.Start(argv[1], std::stoi(argv[1], nullptr, 10));
    } catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}

