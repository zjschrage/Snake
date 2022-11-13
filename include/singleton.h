#pragma once
#include <SFML/Graphics.hpp>
#include "istate.h"

template <typename T>
class Singleton {
    public:
        static T& get() {return *single;}
        static void set(std::unique_ptr<T> singleNew) {single = std::move(singleNew);}

    private:
        Singleton() {}
        static std::unique_ptr<T> single;
};
