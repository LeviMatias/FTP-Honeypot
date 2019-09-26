//
// Created by Matias on 26/09/2019.
// ergo

#ifndef TP3_COMMON_PROXY_H
#define TP3_COMMON_PROXY_H

#include "common_message.h"

class Proxy {
public:

    virtual void Send(Message m);

    Message GetReply();

    void Disconnect();
private:
    //socket
};


#endif //TP3_COMMON_PROXY_H
