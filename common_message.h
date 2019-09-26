//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_COMMON_MESSAGE_H
#define TP3_COMMON_MESSAGE_H

#define LINE_JUMP '\0'

#include <string>

class Message {
public:

    explicit Message(bool is_last);

    explicit Message(std::string msg, bool is_last);

    std::string get_text();

    void set_text(std::string txt);

    bool is_last_messsage();

private:
    std::string text;
    bool is_last;
};


#endif //TP3_COMMON_MESSAGE_H
