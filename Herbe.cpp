#include "Herbe.hpp"

sf::Texture Herbe::herbes;

void Herbe::getAtlas()
{
    herbes.loadFromFile("herbes.png");
}

Herbe::Herbe (sf::Vector2f initialPosition)
    :sf::Sprite()
{
    setTexture(herbes);

    unsigned idHerbe = rand() % 3;

    setTextureRect(sf::IntRect(HERBE_WIDTH * idHerbe, 0, HERBE_WIDTH, HERBE_HEIGHT));

    setPosition(initialPosition);

    scale(3.0f, 3.0f);
}

Herbe::~Herbe()
{}
