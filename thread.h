//
// Created by Matias on 18/09/2019.
//

#ifndef TP1_PROJECT_THREAD_H
#define TP1_PROJECT_THREAD_H


#include <thread>
#include <atomic>
#include "server_command_interpreter.h"

class Thread {
private:
    std::thread thread;
    std::atomic_bool closed{false};

    virtual void Start(CmdInterpreter &interpreter) = 0;

public:
    //runs the thread
    void Run();

    virtual void Close();

    bool IsClosed();

    //joins the thread
    void Join();
};


#endif //TP1_PROJECT_THREAD_H
