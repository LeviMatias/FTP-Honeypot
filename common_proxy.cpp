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

bool Proxy::Send(Message m) {
    char c = m.IsLastMesssage();
    std::string msg = c + m.GetText() + LINE_FEED;
    bool s = !this->skt.Send(std::vector<char>(msg.begin(), msg.end()));
    if (s){
        Disconnect();
    }
    return s;
}

bool Proxy::Ping(){
    Message m("", true);
    return this->Send(m);
}

Message Proxy::GetReply(){
    Message m(true);
    bool r;
    do {
        char c = true;
        r = this->skt.Receive1Byte(&c);
        m.SetIsLast(c);
        std::string msg;
        for (r = this->skt.Receive1Byte(&c);
             r && c != LINE_FEED; r = this->skt.Receive1Byte(&c)){
            //recv 1, check & repeat while tracking r
            msg += c;
        }
        m.SetText(msg);
        std::cout<<m<<std::endl;
        if (!r) this->Disconnect();
    } while (r && m.GetText().empty());//ignore pings
    return m;
}

void Proxy::Disconnect() {
    this->skt.Shutdown();
}

Socket *Proxy::GetSkt() {
    return &this->skt;
}


