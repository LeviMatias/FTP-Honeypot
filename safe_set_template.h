//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SAFE_SET_TEMPLATE_H
#define TP3_SAFE_SET_TEMPLATE_H

#include <set>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <algorithm>

template <class T>
class SafeSet{
public:
SafeSet<T>();
//SafeSet allows multiple threads reading but locks the set when
//its being written to
bool Insert(T elem);

bool Erase(T elem);

std::vector<T> GetAll();

bool Contains(T elem);


private:
    std::set<T> set;
    std::mutex m;
    std::mutex m2;
    bool being_written{};
    bool being_read{};
    std::condition_variable being_written_cv;
    std::condition_variable being_read_cv;

    void LockSet();
};

template<class T>
SafeSet<T>::SafeSet() {
    this->being_written = false;
    this->being_read = false;
}


template<class T>
bool SafeSet<T>::Insert(T elem) {
    std::unique_lock<std::mutex> lock(this->m);
    this->being_written = true;

    auto result = set.insert(elem);

    this->being_written = false;
    this->being_written_cv.notify_all();
    return result.second;//return the result of the insertion
}

template<class T>
bool SafeSet<T>::Erase(T elem) {
    std::unique_lock<std::mutex> lock(this->m);
    this->being_written = true;

    auto it = set.find(elem);
    bool was_found = it != set.end();
    if (was_found){
        set.erase(it);
    }

    this->being_written = false;
    this->being_written_cv.notify_all();
    return was_found;
}

template<class T>
std::vector<T> SafeSet<T>::GetAll() {
    std::vector<T> elems;
    if (being_written){
        LockSet();
    }
    std::for_each(set.begin(),set.end(),[&](T elem){
        elems.emplace_back(elem);
    });
    return elems;
}

template<class T>
bool SafeSet<T>::Contains(T elem) {
    if (being_written){
        LockSet();
    }
    auto it = this->set.find(elem);
    return (it != this->set.end());
}

template<class T>
void SafeSet<T>::LockSet() {
    std::unique_lock<std::mutex> lock(this->m2);
    while(this->being_written){
        this->being_written_cv.wait(lock);
    }
}


#endif //TP3_SAFE_SET_TEMPLATE_H
