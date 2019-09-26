//
// Created by Matias on 26/09/2019.
//

#include "common_proxy.h"

void Proxy::Talk(Message m) {
    char c = m.is_last_messsage();
    std::string msg = m.get_text() + c + LINE_JUMP;
    //send
}

Message Proxy::WaitForReply() {
    return Message(false);
}

void Proxy::Disconnect() {

}
