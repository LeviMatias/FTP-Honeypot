//
// Created by Matias on 18/09/2019.
//

#include "thread.h"

Thread::Thread(){

}

void Thread::Run() {
    //this->thread = std::thread(&Thread::_Run, this, order, total_threads);
}

void Thread::Join() {
    this->thread.join();
}



