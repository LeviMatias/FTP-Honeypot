//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SAFE_SET_TEMPLATE_H
#define TP3_SAFE_SET_TEMPLATE_H

#include <set>
#include <mutex>
#include <vector>
#include <algorithm>

template <class T>
class SafeSet{
public:
    bool Insert(T elem);

    bool Erase(T elem);

    //POS returns a list containing all elements inside the set
    std::vector<T> GetAll();

    bool Contains(T elem);

private:
    std::set<T> set;
    std::mutex m;
};

template<class T>
bool SafeSet<T>::Insert(T elem) {
    std::unique_lock<std::mutex> lock(this->m);
    auto result = set.insert(elem);
    return result.second;//return the result of the insertion
}

template<class T>
bool SafeSet<T>::Erase(T elem) {
    std::unique_lock<std::mutex> lock(this->m);

    auto it = set.find(elem);
    bool was_found = it != set.end();
    if (was_found){
        set.erase(it);
    }
    return was_found;
}

template<class T>
std::vector<T> SafeSet<T>::GetAll() {
    std::unique_lock<std::mutex> lock(m);
    std::vector<T> elems;
    std::for_each(set.begin(),set.end(),[&](T elem){
        elems.emplace_back(elem);
    });
    return elems;
}

template<class T>
bool SafeSet<T>::Contains(T elem) {
    std::unique_lock<std::mutex> lock(m);
    auto it = this->set.find(elem);
    return (it != this->set.end());
}


#endif //TP3_SAFE_SET_TEMPLATE_H
