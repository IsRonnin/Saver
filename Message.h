#pragma once
#include <string>
#include "control.h"
using namespace std;


class Message {
    string _text;
    string _sender;
    string _receiver;
    friend std::ostream& operator<<(std::ostream& os, const Message& C) {
        os << C._text << ":" <<C._sender <<  ":" << C._receiver;
        return os;
    }
public:
    Message(const string& text, const string& sender, const string& receiver) : _text(text), _sender(sender), _receiver(receiver) {};
    Message(const Message& other) : _text(other._text), _sender(other._sender), _receiver(other._receiver) {};
};
