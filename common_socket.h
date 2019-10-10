//
// Created by Matias on 27/09/2019.
//

#ifndef TP3_COMMON_SOCKET_H
#define TP3_COMMON_SOCKET_H

#include <sys/types.h>

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
/*
#include <winsock2.h>
#include <ws2tcpip.h>
*/
#include <unistd.h>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <fcntl.h>

#define S1(x) #x
#define S2(x) S1(x)
#define HERE __FILE__ " : " S2(__LINE__)

#define OFF -1

class Socket {
public:

    //Creates a socket linked to the host and service
    explicit Socket(std::string host, int service, bool is_passive);

    //Creates a socket and sets the internal fd
    // to my_fd, connected_fd is used to indicate
    //the channel through which its going to communicate
    explicit Socket(int my_fd, int connected_fd);

    Socket(const Socket &other);

    //PRE socket must be created with Socket(3)
    //POS connects the thread, throws runtime exception if failed
    void Connect();

    //POS Sends msg through socket
    //Returns true if all message was sent
    //throws runtime exception if error
    bool Send(std::vector<char> msg);

    //POS: Receives 1 byte from the channel
    //returns true if successful, false otherwise
    //runtime error if error
    bool Receive1Byte(char* c);

    //PRE socket must have been created with Socket(3) and passive
    //POS Attemps to bind and listen to the host and service in a NON_BLOCK way
    //throws runtime exception if failed
    void BindAndListen();

    //POS returns whether the socket is connected or not
    bool IsConnected();

    //PRE socket must have successfully called BindAndListen()
    //POS Accepts a connection, if successful returns valid fd
    //otherwise returns -1 (the socket is nonblocking so -1 is common)
    int Accept();

    //Closes the socket and its channel
    void Shutdown();

    ~Socket();

private:
    int fd;
    int connected;
    addrinfo hints;
    addrinfo *result;
    int valid_ai;

    void InitAddrInfo(bool is_passive);

    void ReleaseAddrInfo();

};


#endif //TP3_COMMON_SOCKET_H
