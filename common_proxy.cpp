//
// Created by Matias on 26/09/2019.
//

#include "common_proxy.h"

void Proxy::Connect(){
    this->skt.Connect();
}

bool Proxy::IsConnected() {
    return skt.IsConnected();
}

void Proxy::Send(Message m) {
    char c = m.IsLastMesssage();
    std::string msg = c + m.GetText() + LINE_FEED;
    if (!this->skt.Send(std::vector<char>(msg.begin(), msg.end()))){
        Disconnect();
    }
}

Message Proxy::GetReply() {
    char c = true;
    bool r = this->skt.Receive1Byte(&c);
    Message m(c);
    std::string msg;
    while (r && c!=LINE_FEED){
        r = this->skt.Receive1Byte(&c);
        msg += c;
    }
    m.SetText(msg);
    if (!r) this->Disconnect();
    return m;
}

void Proxy::Disconnect() {
    this->skt.Shutdown();
}

Socket *Proxy::GetSkt() {
    return &this->skt;
}


