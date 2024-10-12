#pragma once
#include <string>
#include "control.h"
using namespace std;


class User {
    
    string _name;
    string _login;
    string _pass;

    friend std::ostream& operator<<(std::ostream& os, const User& C) {
        os << C._name << ":" << C._login << ":" <<C._pass;
        return os;
    }
public:
    User(const string& name, const string& login, const string& pass) : _name(name), _login(login), _pass(pass) {};
    User(const User& other) : _name(other._name), _login(other._login), _pass(other._pass) {};
};
