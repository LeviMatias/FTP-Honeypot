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
    this->text = msg;
    this->is_last = is_last;
}


std::string Message::get_text() {
    return this->text;
}

void Message::set_text(std::string txt) {
    this->text = std::move(txt);
}

bool Message::is_last_messsage() {
    return this->is_last;
}