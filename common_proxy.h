//
// Created by Matias on 26/09/2019.
// ergo

#ifndef TP3_COMMON_PROXY_H
#define TP3_COMMON_PROXY_H


#include "common_message.h"
#include "common_socket.h"

class Proxy {
public:

    explicit Proxy(int skt_fd, int connected_fd):skt(skt_fd, connected_fd){};

    explicit Proxy(std::string host, int port):skt(host, port, false){};

    void Connect();

    bool IsConnected();

    bool Send(Message m);

    Message GetReply();

    void Disconnect();

    bool Ping();

protected:

    Socket* GetSkt();

private:

    Socket skt;
};


#endif //TP3_COMMON_PROXY_H
