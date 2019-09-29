//
// Created by Matias on 18/09/2019.
//

#include "thread.h"

void Thread::Run() {
    this->thread = std::thread(&Thread::Start, this);
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



