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
    std::string msg = c + m.GetText() + LINE_FEED;
    this->skt.Send(std::vector<char>(msg.begin(), msg.end()));
}

Message Proxy::GetReply() {
    char c;
    this->skt.Receive1Byte(&c);
    Message m(c);
    std::string msg;
    while (this->skt.Receive1Byte(&c) && c!=LINE_FEED){
        msg += c;
    }
    m.SetText(msg);
    return m;
}

void Proxy::Disconnect() {
    this->skt.Shutdown();
}

Socket *Proxy::GetSkt() {
    return &this->skt;
}

Proxy::Proxy(int skt_fd, int connected_fd) {
    this->skt = Socket(skt_fd, connected_fd);
}

Proxy::Proxy()=default;
