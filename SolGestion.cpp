#include "SolGestion.hpp"

SolGestion::SolGestion (sf::Vector2f initialPosition)
{
    sols.push_back(Sol (initialPosition));
}

SolGestion::~SolGestion ()
{}

void SolGestion::ajouterGauche()
{
    sf::Vector2f nouvellePosition = sols.front().position;
    nouvellePosition.x -= 300;
    sols.insert(sols.begin(), Sol (nouvellePosition));
}

void SolGestion::ajouterDroite()
{
    sf::Vector2f nouvellePosition = sols.back().position;
    nouvellePosition.x += 300;
    sols.push_back(Sol (nouvellePosition));
}

void SolGestion::supprimerGauche()
{
    sols.erase(sols.begin());
}

void SolGestion::supprimerDroite()
{
    sols.pop_back();
}
