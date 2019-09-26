//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_SAFE_SET_TEMPLATE_H
#define TP3_SAFE_SET_TEMPLATE_H

#include <set>
#include <mutex>

template <class T>
class SafeSet{
public:

private:
    std::set<T> set;
    std::mutex m;
};


#endif //TP3_SAFE_SET_TEMPLATE_H
