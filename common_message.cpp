//
// Created by Matias on 26/09/2019.
//

#include "common_message.h"

#include <utility>

Message::Message(bool is_last) {
    this->body = "";
    this->is_last = is_last;
    this->close_connection = false;
}

Message::Message(std::string msg, bool is_last) {
    this->body = std::move(msg);
    this->is_last = is_last;
    this->close_connection = false;
}


std::string Message::GetBody() {
    return this->body;
}

void Message::SetText(std::string txt) {
    this->body = std::move(txt);
}

bool Message::IsLastMesssage() {
    return this->is_last;
}

std::ostream &operator<<(std::ostream &out, const Message &m){
    out << m.body;
    return out;
}

void Message::SetIsLast(bool s) {
    this->is_last = s;
}

void Message::SetConnectionClosed(bool v){
    this->close_connection = v;
}

bool Message::IsConnectionClosed(){
    return this->close_connection;
}
