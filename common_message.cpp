//
// Created by Matias on 26/09/2019.
//

#include "common_message.h"

#include <utility>

Message::Message(bool is_last) {
    this->text = "";
    this->is_last = is_last;
}

Message::Message(std::string msg, bool is_last) {
    this->text = std::move(msg);
    this->is_last = is_last;
}


std::string Message::GetText() {
    return this->text;
}

void Message::SetText(std::string txt) {
    this->text = std::move(txt);
}

bool Message::IsLastMesssage() {
    return this->is_last;
}

std::ostream &operator<<(std::ostream &out, const Message &m){
    out << m.text;
    return out;
}