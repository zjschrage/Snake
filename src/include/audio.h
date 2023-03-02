#pragma once
#include <SFML/Audio.hpp>
#include "constants.h"
#include "directory.h"

class Audio {
public:

    Audio() {
        eatbuffer.loadFromFile(Directory::get() + PATH_TO_AUDIO + "eat.wav");
        eat.setBuffer(eatbuffer);
        diebuffer.loadFromFile(Directory::get() + PATH_TO_AUDIO + "die.wav");
        die.setBuffer(diebuffer);
    }
    
    sf::SoundBuffer eatbuffer;
    sf::SoundBuffer diebuffer;
    sf::Sound eat;
    sf::Sound die;
};