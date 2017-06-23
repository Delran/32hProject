#include <iostream>

#include "Deer.hpp"

sf::Texture Deer::eating;
sf::Texture Deer::startEating;
sf::Texture Deer::eatingEnd;
sf::Texture Deer::idle;
sf::Texture Deer::idleLook;


void Deer::getAtlas()
{
    eating.loadFromFile("eating.png");
    eatingEnd.loadFromFile("eatingEnd.png");
    startEating.loadFromFile("startEating.png");
    idle.loadFromFile("idle.png");

    idleLook.create(25,32);
    idleLook.loadFromFile("idleLook.png");
}

Deer::Deer(sf::Vector2f initialPosition)
:sf::Sprite()
{
    setTexture(eatingEnd);
    setPosition(initialPosition);
    scale(5, 5);
}

Deer::~Deer()
{

}
void Deer::animate()
{
    loop++;
    if (loop == 120)
    {
        //setTexture(eating, true);
    }
    if (loop == 120)
    {
        setPosition(getPosition().x, 668-5);
        setTexture(startEating, true);
    }
    if (loop == 140)
    {
        setPosition(getPosition().x, 668-60);
        setTexture(idle, true);
    }
    if (loop == 200)
    {
        setPosition(getPosition().x, 668-65);
        setTexture(idleLook, true);
    }
    if (loop == 320)
    {
        setPosition(getPosition().x, 668-60);
        setTexture(idle, true);
    }
    if (loop == 340)
    {
        setPosition(getPosition().x, 668-5);
        setTexture(startEating, true);
    }
    if (loop == 360)
    {
        setPosition(getPosition().x, 668);
        setTexture(eating, true);
        anim = 1;
    }
    if (loop > 370)
    {
        if (loop%20 == 0)
            eatLoop();
    }
    if (loop > 500)
    {
        loop = 0;
    }
}

void Deer::delUpdateRight(int x)
{
    if (getPosition().x > x + 250)
        deletable = true;
}

void Deer::delUpdateLeft()
{
    if (getPosition().x < - 250)
        deletable = true;
}

bool Deer::toDelete()
{
    return deletable;
}

void Deer::eatLoop()
{
    if (anim)
    {
        setTexture(eatingEnd, true);
        anim = 0;
    }
    else
    {
        setTexture(eating, true);
        anim = 1;
    }

}
