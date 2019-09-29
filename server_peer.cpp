//
// Created by Matias on 26/09/2019.
//

#include "server_peer.h"

Peer::Peer(int skt_fd) {
    this->proxy_client = Proxy(skt_fd, skt_fd);
}

void Peer::Start(CmdInterpreter &interpreter) {
    while (proxy_client.IsConnected()){

    }
}
