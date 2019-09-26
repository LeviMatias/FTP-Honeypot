//
// Created by Matias on 26/09/2019.
//

#include "common_proxy.h"

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
