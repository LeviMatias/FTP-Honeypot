//
// Created by Matias on 26/09/2019.
//

#include "common_proxy.h"

void Proxy::Connect(){
    this->skt.Connect();
}

bool Proxy::IsConnected() {
    return this->skt.IsConnected();
}

bool Proxy::Send(Message m) {
    char c = m.IsLastMesssage();
    char c2 = m.IsConnectionClosed();
    std::string msg = c + (c2 + m.GetBody()) + LINE_FEED;
    bool s = this->skt.Send(std::vector<char>(msg.begin(), msg.end()));
    if (!s){
        this->Disconnect();
    }
    return s;
}

bool Proxy::Ping(){//empty packet
    Message m("", true);
    return this->Send(m);
}


Message Proxy::GetReply(){
    Message m(true);
    bool r;
    do {
        char c = RecvSettings(m);
        std::string msg;
        for (r = this->skt.Receive1Byte(&c);
             r && c != LINE_FEED; r = this->skt.Receive1Byte(&c)){
            //recv 1, check & repeat while tracking r
            msg += c;
        }
        m.SetText(msg);
        if (!r) this->Disconnect();
    } while (r && m.GetBody().empty());//ignore pings
    if (m.IsConnectionClosed()) this->Disconnect();
    return m;
}

void Proxy::Disconnect() {    
    this->skt.Shutdown();
}

Socket *Proxy::GetSkt() {
    return &this->skt;
}

char Proxy::RecvSettings(Message &m) {
    char c = true;
    this->skt.Receive1Byte(&c);
    m.SetIsLast(c);
    c = true;
    this->skt.Receive1Byte(&c);
    m.SetConnectionClosed(c);
    return c;
}

Proxy::~Proxy() {
    this->Disconnect();
}


