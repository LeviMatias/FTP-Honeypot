//
// Created by Matias on 18/09/2019.
//

#ifndef TP1_PROJECT_THREAD_H
#define TP1_PROJECT_THREAD_H


#include <thread>

class Thread {
private:
    std::thread thread;

    virtual void Start() = 0;

public:
    explicit Thread();

    //runs the thread with the specified id
    void Run();

    //joins the thread
    void Join();
};


#endif //TP1_PROJECT_THREAD_H
