//
// Created by Matias on 18/09/2019.
//

#include "server_base_thread.h"

void Thread::Run(CmdInterpreter* interpreter) {
    this->thread = std::thread(&Thread::Start, this, interpreter);
}

void Thread::Join() {
    this->thread.join();
}

void Thread::Close() {
    this->closed.store(true);
}

bool Thread::IsClosed() {
    return this->closed.load();
}



