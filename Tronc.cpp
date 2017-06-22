#include "Tronc.hpp"

sf::Texture Tronc::troncs;

void Tronc::getAtlas()
{
    troncs.loadFromFile("troncs.png");
}

Tronc::Tronc (sf::Vector2f initialPosition)
    :sf::Sprite()
{
    setTexture(troncs);

    unsigned idTronc = rand() % 5;

    setTextureRect(sf::IntRect(80 * idTronc, 0, 80, 131));

    setPosition(initialPosition);
}

Tronc::~Tronc()
{}
