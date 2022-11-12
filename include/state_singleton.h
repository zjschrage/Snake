#pragma once
#include <SFML/Graphics.hpp>
#include "istate.h"

class StateSingleton {
    public:
        static IState& getState() {return *currentState;}
        static void setState(std::unique_ptr<IState> state) {currentState = std::move(state);}

    private:
        StateSingleton() {}
        static std::unique_ptr<IState> currentState;
};
