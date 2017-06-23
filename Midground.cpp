#include "Midground.hpp"

sf::Texture Midground::midgrounds;

void Midground::getAtlas()
{
    midgrounds.loadFromFile("midgrounds.png");
}

Midground::Midground (sf::Vector2f initialPosition)
    :sf::Sprite()
{
    setTexture(midgrounds);

    unsigned idMidground = rand() % 3;

    setTextureRect(sf::IntRect(MIDGROUND_WIDTH * idMidground, 0, MIDGROUND_WIDTH, MIDGROUND_HEIGHT));

    setPosition(initialPosition);

    scale(3.0f, 3.0f);
}

Midground::~Midground()
{}
