//
// Created by Matias on 26/09/2019.
//

#include "client_client.h"

#include <utility>

void Client::Start(std::string host, int port) {
    try {
        this->server.Connect(std::move(host), port);
    } catch(...) {
       return;
    }
    bool msg_end = false;
    std::string line;
    try {
        while (server.IsConnected()) {
            while (!msg_end) {
                Message msg = server.GetReply();
                printf("print msg <<");
                msg_end = msg.IsLastMesssage();
            }
            getline(std::cin, line);
            Message msg = Message(line, true);
            server.Send(msg);
        }
    } catch(...) {
        return; // connection ended
    }
}