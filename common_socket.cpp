//
// Created by Matias on 27/09/2019.
//

#include "common_socket.h"

Socket::Socket(std::string host, int service, bool is_passive){
    this->fd = 0;
    this->connected = OFF;
    InitAddrInfo(is_passive);
    std::string port = std::to_string(service);
    this->valid_ai = getaddrinfo(host.c_str(),\
                        port.c_str(), \
                        &(this->hints),
                              &this->result);
    if (this->valid_ai != 0) {
        throw std::runtime_error((std::string)gai_strerror(this->valid_ai)\
        + "get addrinfo error" + HERE);
    }
}

Socket::Socket(int my_fd, int connected_fd){
    this->fd = my_fd;
    this->connected = connected_fd;
    InitAddrInfo(false);
}

void Socket::Connect() {
    int skt = 0;
    if (this->valid_ai != 0) return;
    for (auto ptr = this->result; ptr != nullptr && skt == 0; ptr = ptr->ai_next){
        skt = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (skt > 0) {
            this->fd = skt;
            int s = connect(this->fd, ptr->ai_addr, ptr->ai_addrlen);
            skt = 0;
            if (s != -1) {
                this->connected = this->fd;
                return;
            }
        }
    }
    close(this->fd);
    throw std::runtime_error((std::string)strerror(errno)\
                + "could not connect" + HERE);
}

bool Socket::Send(std::vector<char> msg) {
    unsigned int sent = 0;
    int s = 0;
    while (sent < msg.size() && this->connected != OFF && this->fd != OFF) {
        s = send(this->connected, &msg[sent], msg.size() - sent, MSG_NOSIGNAL);
        if (s > 0){
            sent += s;
        }
    }
    if (s < 0) {
        throw std::runtime_error((std::string)strerror(errno)+\
                                    " send error" + HERE);
    }
    return (msg.size()<=sent);
}

int Socket::Accept() {
    int peer_fd = accept(this->fd, nullptr, nullptr);
    return peer_fd;
}

void Socket::BindAndListen() {
    int s = -1;
    const int val = 1; //configure socket to reuse address if TIME WAIT
    this->fd = socket(this->result->ai_family, this->result->ai_socktype, this->result->ai_protocol);
    setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR,
               reinterpret_cast<const char *>(&val), sizeof(val));

    for (auto ptr = this->result; ptr != nullptr && s == -1; ptr = ptr->ai_next){
        s = bind(this->fd, ptr->ai_addr, ptr->ai_addrlen);
    }
    if (s != -1){
        s = listen(this->fd, 10);
    }
    if (s == -1){
        throw std::runtime_error((std::string)strerror(errno)+\
                                " bind error " + HERE );
    }
}

bool Socket::Receive1Byte(char* c){
    int s = 1;
    int r = 0;

    while (r < 1 && s > 0 && this->connected != -1) {
        s = recv(this->connected, c, 1, 0);
        if (s<0){ // there was an error
            throw std::runtime_error((std::string)strerror(errno)+\
            " recv error " + HERE);
        } else{
            r += s;
        }
    }
    return (s > 0);
}

bool Socket::IsConnected() {
    return (this->connected != OFF) && (this->fd != OFF);
}


void Socket::Shutdown() {
    if (this->fd != OFF){
        if (this->connected != OFF && shutdown(this->connected, SHUT_RDWR) == -1){
            printf("Closing skt error: %s\n", strerror(errno));
        }
        if (this->connected != OFF && this->connected != this->fd){
            close(this->connected);
        }
        close(this->fd);
        this->fd = OFF;
        this->connected = OFF;
    }
}

Socket::~Socket() {
    this->Shutdown();
}

Socket::Socket(const Socket &other){
    this->fd = other.fd;
    this->connected = other.connected;
    InitAddrInfo(false);
}
