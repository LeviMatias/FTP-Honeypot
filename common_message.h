//
// Created by Matias on 26/09/2019.
//

#ifndef TP3_COMMON_MESSAGE_H
#define TP3_COMMON_MESSAGE_H

#define LINE_JUMP '\0'
#define IS_LAST '1'
#define ISNT_LAST '2'

#include <string>

class Message {
public:

    explicit Message(bool is_last);

    explicit Message(std::string msg, bool is_last);

    std::string GetText();

    void SetText(std::string txt);

    bool IsLastMesssage();

private:
    std::string text;
    char is_last;

    void SetIsLast(bool v);
};


#endif //TP3_COMMON_MESSAGE_H
