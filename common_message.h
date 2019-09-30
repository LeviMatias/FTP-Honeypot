//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_COMMON_MESSAGE_H
#define TP3_COMMON_MESSAGE_H

#define LINE_FEED '\n'

#include <string>
#include <iostream>

class Message {
public:

    explicit Message(bool is_last);

    explicit Message(std::string msg, bool is_last);

    std::string GetText();

    void SetText(std::string txt);

    bool IsLastMesssage();

    friend std::ostream & operator << (std::ostream &out, const Message &m);


private:
    std::string text;
    bool is_last;
};


#endif //TP3_COMMON_MESSAGE_H
