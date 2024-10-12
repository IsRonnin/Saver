#include "control.h"
#include <sys/stat.h>

bool reader::fileExists(const string& filename) {
    std::ifstream file(filename);
    return file.good();
}

bool reader::get_from_file(vector<Message>& v, const string& fileName) {
    if (!fileExists(fileName)) {
        std::ofstream file(fileName);
        chmod(fileName.c_str(), S_IRWXU);
        file.close();
        return false;
    }
    else {
        std::ifstream file(fileName);
        string data, temp;

        while (getline(file, data)) {
        vector<string> dt;
            for (long unsigned int i = 0; i < data.size(); ++i) {
                if (data.at(i) != ':' && i != (data.size() - 1)) {
                    temp = temp + data.at(i);
                }
                else {
                    dt.emplace_back(temp);
                    temp.erase();
                }
            }
            v.emplace_back(dt.at(0), dt.at(1), dt.at(2));
        }
        file.close();

        return true;
    }
}

bool reader::get_from_file(vector<User>& v, const string& fileName) {
    if (!fileExists(fileName)) {
        std::ofstream file(fileName);
        chmod(fileName.c_str(), S_IRWXU);
        file.close();
        return false;
    }
    else {
        std::ifstream file(fileName);
        string data, temp;

        while (getline(file, data)) {
            vector<string> dt;
            for (long unsigned int i = 0; i < data.size(); ++i) {
                if (data.at(i) != ':' && i != (data.size() - 1)) {
                    temp = temp + data.at(i);
                }
                else {
                    dt.emplace_back(temp);
                    temp.erase();
                }
            }
            v.emplace_back(dt.at(0), dt.at(1), dt.at(2));
        }
        file.close();
        
        return true;
    }
}

bool reader::convert_to_file(const vector<Message>& v, const string& fileName) {
    if (!fileExists(fileName)) {
        std::ofstream file(fileName);
        chmod(fileName.c_str(), S_IRWXU);
    }

    ofstream file(fileName);

    for (unsigned long int i = 0; i < v.size(); ++i) {
        file << v.at(i);
        if (i != (v.size() - 1)) file << "\n";
    }
    return true;

};

bool reader::convert_to_file(const vector<User>& v, const string& fileName) {
    if (!fileExists(fileName)) {
        std::ofstream file(fileName);
        chmod(fileName.c_str(), S_IRWXU);
        file.close();
    }
    ofstream file(fileName);

    for (unsigned long int i = 0; i < v.size(); ++i) {
        file << v.at(i);
        if (i != (v.size() - 1)) file << "\n";
    }
    return true;
};
