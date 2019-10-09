//
// Created by Matias on 28/09/2019.
//

#include "server_acceptor_thread.h"

void AcceptorThread::Start(CmdInterpreter &interpreter) {
    try {
        this->skt.BindAndListen();
        while (!this->IsClosed()) {
            int peer = skt.Accept();
            if (peer != -1) {
                peers.emplace_back(peer);
                peers.back().Run(interpreter);
            }
            auto i = peers.begin();
            while(i != peers.end()){
                if (i->IsClosed()) {
                    i->Join();
                    i = peers.erase(i);
                }
            }
        }
        Close();
    }catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
        Close();
    }
}

void AcceptorThread::Close(){
    auto i = peers.begin();
    while(i != peers.end()){
        i->Close();
        i->Join();
    }
    skt.Shutdown();
    Thread::Close();
}
