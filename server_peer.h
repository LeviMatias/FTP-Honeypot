//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SERVER_PEER_H
#define TP3_SERVER_PEER_H


#include "common_proxy.h"
#include "thread.h"
#include "server_command_interpreter.h"

class Peer : public Thread {
public:

    explicit Peer(int skt_fd);

private:
    Proxy proxy_client;

    virtual void Start(CmdInterpreter &interpreter);
};


#endif //TP3_SERVER_PEER_H
