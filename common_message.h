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
    //creates a new message marked as last in a series
    explicit Message(bool is_last);

    //creates a new message marked as last in a series with body = msg
    explicit Message(std::string msg, bool is_last);

    //returns string stored as message body
    std::string GetBody();

    //sets text as message body
    void SetText(std::string txt);

    //sets whether the message is the last in a series
    void SetIsLast(bool s);

    bool IsLastMesssage();

    //sets whether the message indicates end of connection
    void SetConnectionClosed(bool v);

    bool IsConnectionClosed();

    friend std::ostream & operator << (std::ostream &out, const Message &m);

private:
    std::string body;
    bool is_last;
    bool close_connection;
};


#endif //TP3_COMMON_MESSAGE_H
