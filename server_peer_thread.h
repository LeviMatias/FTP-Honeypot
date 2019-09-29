//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SERVER_PEER_THREAD_H
#define TP3_SERVER_PEER_THREAD_H


#include "common_proxy.h"
#include "thread.h"
#include "server_command_interpreter.h"
#include "server_user_profile.h"

class Peer : public Thread {
public:

    explicit Peer(int skt_fd);

    void Close() override;

private:
    Proxy proxy_client;
    UserProfile profile;

    virtual void Start(CmdInterpreter *interpreter);
};


#endif //TP3_SERVER_PEER_THREAD_H
