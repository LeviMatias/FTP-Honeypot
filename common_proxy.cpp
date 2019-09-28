//
// Created by Matias on 26/09/2019.
//

#include "common_proxy.h"

void Proxy::Connect(std::string host, int port) {
    this->skt = Socket(std::move(host), port, false);
    this->skt.Connect();
}

bool Proxy::IsConnected() {
    return skt.IsConnected();
}

void Proxy::Send(Message m) {
    char c = m.IsLastMesssage();
    std::string msg = m.GetText() + LINE_JUMP;
    //send
}

Message Proxy::GetReply() {
    return Message(false);
}

void Proxy::Disconnect() {

}

Socket *Proxy::GetSkt() {
    return &this->skt;
}
