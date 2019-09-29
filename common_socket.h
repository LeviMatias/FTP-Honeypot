//
// Created by Matias on 27/09/2019.
//

#ifndef TP3_COMMON_SOCKET_H
#define TP3_COMMON_SOCKET_H

#include <sys/types.h>
/*
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
*/
#include <unistd.h>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <fcntl.h>

#include <winsock2.h>
#include <ws2tcpip.h>


#define NOT_CONNECTED -1

class Socket {
public:

    Socket();

    explicit Socket(std::string host, int service, bool is_passive);

    explicit Socket(int my_fd, int connected_fd);

    void Connect();

    void Send(std::vector<char> msg);

    bool Receive1Byte(char* c);

    void BindAndListen();

    bool IsConnected();

    int Accept();

    void Shutdown();

    ~Socket();

private:
    int fd;
    int connected;

    class AddrInfo{
        public:
        addrinfo hints;
        addrinfo *result;
        int s;

        explicit AddrInfo(bool is_passive){
            memset(&(this->hints), 0, sizeof(this->hints));
            this->hints.ai_family = AF_INET;       /* IPv4 */
            this->hints.ai_socktype = SOCK_STREAM; /* TCP */
            if (is_passive){
                this->hints.ai_flags = AI_PASSIVE;
            } else {
                this->hints.ai_flags = 0;
            }
        }

        ~AddrInfo(){
            if (s == 0) {
                freeaddrinfo(this->result);
            }
        }
    };

    AddrInfo ai;
};


#endif //TP3_COMMON_SOCKET_H
