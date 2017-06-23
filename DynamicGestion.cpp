#include "DynamicGestion.hpp"

DynamicGestion::DynamicGestion (sf::Vector2f initialPosition)
{
    elements.push_back(new Arbre (initialPosition));
}

DynamicGestion::~DynamicGestion ()
{}

void DynamicGestion::update(int screenWidth)
{
    // SOL ET HERBE
    if (elements.front()->getPosition().x > -600)
    {
        ajouterGauche();
    }
    else if (elements.front()->getPosition().x < -1000)
    {
        supprimerGauche();
    }

    if (elements.back()->getPosition().x < screenWidth + 600)
    {
        ajouterDroite();
    }
    else if (elements.back()->getPosition().x > screenWidth + 1000)
    {
        supprimerDroite();
    }
}

void DynamicGestion::ajouterGauche()
{
    sf::Vector2f nouvellePosition = elements.front()->getPosition();
    nouvellePosition.x -= (rand() % 400 + 200);
    elements.insert(elements.begin(), new Arbre (nouvellePosition));
}

void DynamicGestion::ajouterDroite()
{
    sf::Vector2f nouvellePosition = elements.back()->getPosition();
    nouvellePosition.x += (rand() % 400 + 200);
    elements.push_back(new Arbre (nouvellePosition));
}

void DynamicGestion::supprimerGauche()
{
    if (elements.size() != 0)
        elements.erase(elements.begin());
}

void DynamicGestion::supprimerDroite()
{
    if (elements.size() != 0)
        elements.pop_back();
}
