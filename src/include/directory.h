#pragma once
#include <string>

class Directory {
public:
    static void set(std::string wd);
    static std::string get();;
};