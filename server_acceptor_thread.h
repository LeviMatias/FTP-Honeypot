//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_ACCEPTOR_THREAD_H
#define TP3_SERVER_ACCEPTOR_THREAD_H

#include <string>
#include <vector>
#include "thread.h"
#include "server_command_interpreter.h"
#include "common_socket.h"
#include "server_peer_thread.h"

class AcceptorThread : public Thread {
public:

    AcceptorThread(std::string host, int service);

    void Close();

private:
    Socket skt;
    std::vector<Peer> peers;

    virtual void Start(CmdInterpreter *interpreter);
};


#endif //TP3_SERVER_ACCEPTOR_THREAD_H
