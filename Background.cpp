#include "Background.hpp"

sf::Texture Background::backgrounds;

void Background::getAtlas()
{
    backgrounds.loadFromFile("background.png");
}

Background::Background (sf::Vector2f initialPosition)
    :sf::Sprite()
{
    setTexture(backgrounds);
    setPosition(initialPosition);

    scale(3.0f, 3.0f);
}

Background::~Background()
{}
