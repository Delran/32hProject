#include "StaticGestion.hpp"

StaticGestion::StaticGestion (sf::Vector2f initialPosition)
{
    sols.push_back(Sol (initialPosition));
    initialPosition.y -= 5;
    herbes.push_back(Herbe (initialPosition));
    initialPosition.y -= 930;
    midgrounds.push_back(Midground (initialPosition));
    initialPosition.y += 400;
    backgrounds.push_back(Background (initialPosition));
}

StaticGestion::~StaticGestion ()
{}

void StaticGestion::update(int screenWidth)
{
    // SOL ET HERBE
    if (sols.front().getPosition().x > -SOL_WIDTH * 2)
    {
        ajouterSolGauche();
    }
    else if (sols.front().getPosition().x < -SOL_WIDTH * 4)
    {
        supprimerSolGauche();
    }

    if (sols.back().getPosition().x < screenWidth + SOL_WIDTH * 2)
    {
        ajouterSolDroite();
    }
    else if (sols.back().getPosition().x > screenWidth + SOL_WIDTH * 4)
    {
        supprimerSolDroite();
    }

    // MIDGROUND
    if (midgrounds.front().getPosition().x > -MIDGROUND_WIDTH * 2)
    {
        ajouterMidgroundGauche();
    }
    else if (midgrounds.front().getPosition().x < -MIDGROUND_WIDTH * 4)
    {
        supprimerMidgroundGauche();
    }

    if (midgrounds.back().getPosition().x < screenWidth + MIDGROUND_WIDTH * 2)
    {
        ajouterMidgroundDroite();
    }
    else if (midgrounds.back().getPosition().x > screenWidth + MIDGROUND_WIDTH * 4)
    {
        supprimerMidgroundDroite();
    }

    // BACKGROUND
    if (backgrounds.front().getPosition().x > -BACKGROUND_WIDTH * 2)
    {
        ajouterBackgroundGauche();
    }
    else if (backgrounds.front().getPosition().x < -BACKGROUND_WIDTH * 4)
    {
        supprimerBackgroundGauche();
    }

    if (backgrounds.back().getPosition().x < screenWidth + BACKGROUND_WIDTH * 2)
    {
        ajouterBackgroundDroite();
    }
    else if (backgrounds.back().getPosition().x > screenWidth + BACKGROUND_WIDTH * 4)
    {
        supprimerBackgroundDroite();
    }
}

void StaticGestion::ajouterSolGauche()
{
    sf::Vector2f nouvellePosition = sols.front().getPosition();
    nouvellePosition.x -= SOL_WIDTH * 2;
    sols.insert(sols.begin(), Sol (nouvellePosition));
    nouvellePosition.y -= 5;
    herbes.insert(herbes.begin(), Herbe (nouvellePosition));
}

void StaticGestion::ajouterSolDroite()
{
    sf::Vector2f nouvellePosition = sols.back().getPosition();
    nouvellePosition.x += SOL_WIDTH * 2;
    sols.push_back(Sol (nouvellePosition));
    nouvellePosition.y -= 5;
    herbes.push_back(Herbe (nouvellePosition));
}

void StaticGestion::supprimerSolGauche()
{
    if (sols.size() != 0)
        sols.erase(sols.begin());
    if (herbes.size() != 0)
        herbes.erase(herbes.begin());
}

void StaticGestion::supprimerSolDroite()
{
    if (sols.size() != 0)
        sols.pop_back();
    if (herbes.size() != 0)
        herbes.pop_back();
}

void StaticGestion::ajouterMidgroundGauche()
{
    sf::Vector2f nouvellePosition = midgrounds.front().getPosition();
    nouvellePosition.x -= MIDGROUND_WIDTH * 2;
    midgrounds.insert(midgrounds.begin(), Midground (nouvellePosition));
}

void StaticGestion::ajouterMidgroundDroite()
{
    sf::Vector2f nouvellePosition = midgrounds.back().getPosition();
    nouvellePosition.x += MIDGROUND_WIDTH * 2;
    midgrounds.push_back(Midground (nouvellePosition));
}

void StaticGestion::supprimerMidgroundGauche()
{
    if (midgrounds.size() != 0)
        midgrounds.erase(midgrounds.begin());
}

void StaticGestion::supprimerMidgroundDroite()
{
    if (midgrounds.size() != 0)
        midgrounds.pop_back();
}

void StaticGestion::ajouterBackgroundGauche()
{
    sf::Vector2f nouvellePosition = backgrounds.front().getPosition();
    nouvellePosition.x -= BACKGROUND_WIDTH * 2;
    backgrounds.insert(backgrounds.begin(), Background (nouvellePosition));
}

void StaticGestion::ajouterBackgroundDroite()
{
    sf::Vector2f nouvellePosition = backgrounds.back().getPosition();
    nouvellePosition.x += BACKGROUND_WIDTH * 2;
    backgrounds.push_back(Background (nouvellePosition));
}

void StaticGestion::supprimerBackgroundGauche()
{
    if (backgrounds.size() != 0)
        backgrounds.erase(backgrounds.begin());
}

void StaticGestion::supprimerBackgroundDroite()
{
    if (backgrounds.size() != 0)
        backgrounds.pop_back();
}
