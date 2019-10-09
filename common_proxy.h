//
// Created by Matias on 26/09/2019.
// ergo

#ifndef TP3_COMMON_PROXY_H
#define TP3_COMMON_PROXY_H


#include "common_message.h"
#include "common_socket.h"

class Proxy {
public:

    //POS creates a connected proxy with the specified fd
    explicit Proxy(Socket skt);

    //POS creates an unconnected proxy to the specified address
    explicit Proxy(std::string host, int port):skt(host, port, false){};

    //PRE porxy must be unconnected
    //POS attempts to connect, throwing a runtime exception if failed
    void Connect();

    //returns if proxy is connected
    bool IsConnected();

    //POS sends message m through the channel
    //true if successful, false if connection ended
    //disconnects if connection ended
    //runtime exception on error
    bool Send(Message m);

    //POS yields until message is received
    //disconnects on connection closed
    //runtime exception on error
    Message GetReply();

    //disconnects from channel
    void Disconnect();

    //POS pings the other end of the channel
    //true if the channel is valid, false and disconnects otherwise
    bool Ping();

protected:
    Socket* GetSkt();

private:
    Socket skt;

    char RecvSettings(Message &m);
};


#endif //TP3_COMMON_PROXY_H
