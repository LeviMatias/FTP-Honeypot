//
// Created by Matias on 26/09/2019.
//

#include "server_server.h"

Server::Server(const std::string &config_path) {
    this->ReadConfig(config_path);
    interpreter.LoadConfig(this->config);
}


void Server::ReadConfig(const std::string& config_name){
    std::ifstream file;
    file.open(config_name, std::ios::in);
    if (!file.good()) throw std::runtime_error("error opening file");

    std::string line;
    while (getline(file, line) && !file.eof()){
        const auto conf = line.substr(0, line.find('='));
        auto l = conf.length() + 1;
        config.Add(conf, line.substr(l, line.length() - l));
    }
    file.close();
}

void Server::Run(const int service){
    AcceptorThread acceptor("0",service);
    acceptor.Run(&interpreter);

    std::string line;
    UserProfile user;
    while (getline(std::cin>> std::ws, line) && line != "q"){
        auto msgs = interpreter.ExecuteCommand(user, line);
        for_each(msgs.begin(),msgs.end(),[&](Message &m){
            std::cout << m;
        });
    }
    acceptor.Close();
    acceptor.Join();
    printf("Server logout");
}

void Server::Serve(const int service){
    try{
        Run(service);
    } catch (std::runtime_error &e){
        std::cout <<"Run server error "<< e.what()<< std::endl;
    }
}