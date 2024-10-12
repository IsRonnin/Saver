#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "User.h"
#include "Message.h"

using namespace std;


class reader {
public:
    bool fileExists(const string& filename);
    reader() {};

    bool get_from_file(vector<Message>& v, const string& fileName);
    bool get_from_file(vector<User>& v, const string& fileName);

    bool convert_to_file(const vector<Message>& v, const string& fileName);
    bool convert_to_file(const vector<User>& v, const string& fileName);
};
