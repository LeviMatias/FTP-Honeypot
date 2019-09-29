//
// Created by Matias on 28/09/2019.
//

#include "server_acceptor_thread.h"

AcceptorThread::AcceptorThread(std::string host, int service) {
    this->skt = Socket(host, service, true);
}

void AcceptorThread::Start(CmdInterpreter &interpreter) {
    this->skt.BindAndListen();
    while (!this->IsClosed()){
        int peer = skt.Accept();
        if (peer != -1){

        }
    }
}

void AcceptorThread::Close(){
    skt.Shutdown();
    Thread::Close();
}
