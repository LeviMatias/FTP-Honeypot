//
// Created by Matias on 26/09/2019.
//ergo

#ifndef TP3_COMMON_PROXY_H
#define TP3_COMMON_PROXY_H

#include "common_message.h"

class Proxy {

    void Talk(Message m);

    Message WaitForReply();

    void Disconnect();
private:
    //socket
};


#endif //TP3_COMMON_PROXY_H
