#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/window.hpp>

using namespace std;
using namespace sf;

class Animation
{
private:
    //variables
    Vector2u imageCount;
    Vector2u currentImage;
	float deltaTime;
    float totalTime;
    float switchTime;

    //functions


public:
    //variables
    IntRect uvRect;

    //constructor && destructor
    Animation(sf::Texture *texture, Vector2u imageCount, float switchTime);
    virtual ~Animation();
    void update(float deltaTime, int row);

};

