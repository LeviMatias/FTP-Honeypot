//
// Created by Matias on 26/09/2019.
//

#include "server_peer_thread.h"

Peer::Peer(int skt_fd) {
    this->proxy_client = Proxy(skt_fd, skt_fd);
}

void Peer::Start(CmdInterpreter *interpreter) {
    std::vector<Message> msgs;
    msgs.emplace_back(Message(interpreter->GetFromConfig("newClient"),true));

    while (proxy_client.IsConnected()){
        for_each(msgs.begin(), msgs.end(), [&](Message &m){
           proxy_client.Send(m);
        });
        Message m = proxy_client.GetReply();
        msgs = interpreter->ExecuteCommand(profile, m.GetText());
    }
}
