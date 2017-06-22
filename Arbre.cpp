#include "Arbre.hpp"

sf::Texture Arbre::arbres;

void Arbre::getAtlas()
{
    arbres.loadFromFile("arbres.png");
}

Arbre::Arbre (sf::Vector2f initialPosition)
    :sf::Sprite()
{
    setTexture(arbres);

    unsigned idArbre = rand() % 8;

    setTextureRect(sf::IntRect(200 * idArbre, 0, 200, 165));

    setPosition(initialPosition);

    scale(5.0f, 5.0f);
}

Arbre::~Arbre()
{}
