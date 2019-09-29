//
// Created by Matias on 29/09/2019.
//

#include "server_server.h"
int main_(int argc, char** argv)
{
    std::cout<<"Hello, Server!"<<std::endl;
    try {
        Server server(argv[2]);
        server.Serve(std::stoi(argv[1], nullptr, 10));
    } catch (std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
