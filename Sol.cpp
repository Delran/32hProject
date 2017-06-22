#include "Sol.hpp"

sf::Texture Sol::sols;

void Sol::getAtlas()
{
    sols.loadFromFile("sols.png");
}

Sol::Sol (sf::Vector2f initialPosition)
    :sf::Sprite(), position (initialPosition)
{
    setTexture(sols);

    unsigned idSol = rand() % 4;

    setTextureRect(sf::IntRect(160 * idSol, 0, 160, 33));

    setPosition(initialPosition);

    scale(3.0f, 3.0f);
}

Sol::~Sol()
{}
