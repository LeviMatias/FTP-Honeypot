//
// Created by Matias on 27/09/2019.
//

#include "common_socket.h"

//TODO
// -Replace MSG_NOSIGNAL & SHUTDOWN_RD WITH NETDB CONSTANTS
// -throw exceptions instead of errors

Socket::Socket(std::string host, int service, bool is_passive) : ai(is_passive) {
    this->fd = 0;
    this->connected = NOT_CONNECTED;

    int s = getaddrinfo(reinterpret_cast<const char *>(host[0]),\
                        reinterpret_cast<const char *>(service), \
                        &(this->ai.hints), &this->ai.result);
    if (s != 0) {
        printf("Throw Ex Error in getaddrinfo: %s\n", gai_strerror(s));
    }
}

void Socket::Connect() {
    int skt = 0;
    for (auto ptr = ai.result; ptr != nullptr && skt == 0; ptr = ptr->ai_next) {
        skt = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (skt == -1) {
            printf("Error in socket init: %s\n", strerror(errno));
        } else {
            this->fd = skt;
            int s = connect(this->fd, ptr->ai_addr, ptr->ai_addrlen);
            if (s == -1) {
                printf("Error in connection: %s\n", strerror(errno));
                close(this->fd);
                skt = 0;
            } else {
                this->connected = this->fd;
            }
        }
    }
}

void Socket::Shutdown() {
    if (this->fd != -1){
        int SHUT_RDWR = 2;
        if (this->connected != -1 && shutdown(this->connected, SHUT_RDWR) == -1){
            printf("Closing connection error: %s\n", strerror(errno));
        }
        if (this->connected != -1 && this->connected != this->fd){
            close(this->connected);
        }
        close(this->fd);
    }
}

void Socket::Send(std::vector<char> msg) {
    int sent = 0;
    int s = 0;
    bool is_the_socket_valid = true;
    while (sent < msg.size() && is_the_socket_valid) {
        int MSG_NOSIGNAL = 0;
        s = send(this->connected, &msg[sent], msg.size() - sent, MSG_NOSIGNAL);

        if (s <= 0) {
            is_the_socket_valid = false;
        } else {
            sent += s;
        }
    }

    if (!is_the_socket_valid) {
        printf("Error in connection: %s\n", strerror(errno));
    }
}

int Socket::Accept() {
    int fd = accept(this->fd, nullptr, nullptr);
    if (fd != -1){
        this->connected = fd;
    }
    return fd;
}

void Socket::BindAndListen() {
    int s = -1;
    int val = 1; //configure socket to reuse address if TIME WAIT
    setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR,
               reinterpret_cast<const char *>(&val), sizeof(val));

    for (auto ptr = ai.result; ptr != nullptr && s == -1; ptr = ptr->ai_next) {
        s = bind(this->fd, ptr->ai_addr, ptr->ai_addrlen);
    }
    if (s != -1){
        s = listen(this->fd, 10);
    }
    if (s == -1){
        printf("Error: %s\n", strerror(errno));
    }
}

bool Socket::Receive1Byte(char* c){
    std::vector<char> msg;
    int s = 1;
    int r = 0;

    while (r < 1 && s > 0 && this->connected != -1) {
        s = recv(this->connected, c, 1, 0);
        if (s == -1) { // there was an error
            printf("Error: %s\n", strerror(errno));
        } else {
            r += s;
        }
    }
    return (s!=-1);
}
