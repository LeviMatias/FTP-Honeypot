//
// Created by Matias on 26/09/2019.
//

#include "common_message.h"

#include <utility>

Message::Message(bool is_last) {
    this->text = "";
    this->SetIsLast(is_last);
}

Message::Message(std::string msg, bool is_last) {
    this->text = msg;
    this->SetIsLast(is_last);
}


std::string Message::GetText() {
    return this->text;
}

void Message::SetText(std::string txt) {
    this->text = std::move(txt);
}

bool Message::IsLastMesssage() {
    return this->is_last == IS_LAST;
}

void Message::SetIsLast(bool v) {
    this->is_last = (v) ? IS_LAST : ISNT_LAST;
}
