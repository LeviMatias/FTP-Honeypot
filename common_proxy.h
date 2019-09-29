//
// Created by Matias on 26/09/2019.
// ergo

#ifndef TP3_COMMON_PROXY_H
#define TP3_COMMON_PROXY_H


#include "common_message.h"
#include "common_socket.h"

class Proxy {
public:

    Proxy();

    explicit Proxy(int skt_fd, int connected_fd);

    void Connect(std::string host, int port);

    bool IsConnected();

    void Send(Message m);

    Message GetReply();

    void Disconnect();

protected:

    Socket* GetSkt();

private:

    Socket skt;
};


#endif //TP3_COMMON_PROXY_H
