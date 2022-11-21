#pragma once
#include <SFML/Audio.hpp>

class Audio {
public:

    Audio() {
        eatbuffer.loadFromFile("aud/eat.wav");
        eat.setBuffer(eatbuffer);
        diebuffer.loadFromFile("aud/die.wav");
        die.setBuffer(diebuffer);
    }
    
    sf::SoundBuffer eatbuffer;
    sf::SoundBuffer diebuffer;
    sf::Sound eat;
    sf::Sound die;
};