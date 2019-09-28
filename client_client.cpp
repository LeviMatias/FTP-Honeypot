//
// Created by Matias on 26/09/2019.
//

#include "client_client.h"

#include "server_command_interpreter.h"
#include <algorithm>


void Client::Start(std::string host, int port) {
    try {
        this->server.Connect(host, port);
    } catch(const std::runtime_error &e) {
       std::cout << e.what() << std::endl;
    }
    bool msg_end = false;
    std::string line;
    CmdInterpreter interpreter;
    try {
        while ( true || server.IsConnected()) {
            while (msg_end) {
                Message msg = server.GetReply();
                printf("print msg <<");
                msg_end = msg.IsLastMesssage();
            }
            getline(std::cin>> std::ws, line);
            Message msg = Message(line, true);
            std::cout << msg;
            //server.Send(msg);
            auto r = interpreter.ExecuteCommand(msg.GetText());
            std::for_each(r.begin(), r.end(), [&](Message& m){
                std::cout << m;
            });
        }
    } catch(...) {
        return; // connection ended
    }
}