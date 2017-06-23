#include "Sol.hpp"

sf::Texture Sol::sols;

void Sol::getAtlas()
{
    sols.loadFromFile("sols.png");
}

Sol::Sol (sf::Vector2f initialPosition)
    :sf::Sprite()
{
    setTexture(sols);

    unsigned idSol = rand() % 4;

    setTextureRect(sf::IntRect(SOL_WIDTH * idSol, 0, SOL_WIDTH, SOL_HEIGHT));

    setPosition(initialPosition);

    scale(3.0f, 3.0f);
}

Sol::~Sol()
{}
