//
// Created by Matias on 28/09/2019.
//

#ifndef TP3_SERVER_ACCEPTOR_THREAD_H
#define TP3_SERVER_ACCEPTOR_THREAD_H

#include <string>
#include <list>
#include "server_base_thread.h"
#include "server_command_interpreter.h"
#include "common_socket.h"
#include "server_peer_thread.h"

class AcceptorThread : public Thread {
public:

    AcceptorThread(std::string host, int service):skt(host, service, true){};

    void Close() override;

private:
    Socket skt;
    std::list<Peer> peers;

    void Start(CmdInterpreter *interpreter) override;
};


#endif //TP3_SERVER_ACCEPTOR_THREAD_H
