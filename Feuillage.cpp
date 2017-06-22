#include "Feuillage.hpp"

sf::Texture Feuillage::feuillages;

void Feuillage::getAtlas()
{
    feuillages.loadFromFile("feuillages.png");
}

Feuillage::Feuillage (sf::Vector2f initialPosition)
{
    setTexture(feuillages);

    unsigned idFeuillage = rand() % 4;

    setTextureRect(sf::IntRect(100 * idFeuillage, 0, 100, 79));

    setPosition(initialPosition);
}

Feuillage::~Feuillage()
{}
