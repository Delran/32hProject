#include "Arbre.hpp"
#include "SolGestion.hpp"

#include <iostream>

int main()
{
    Arbre::getAtlas();
    Sol::getAtlas();

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Forest", sf::Style::Fullscreen);
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Forest");

    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    SolGestion solGestion (sf::Vector2f(0.0f, 750.0f));
    std::vector<sf::Sprite*> decorations;
    decorations.push_back(new Arbre (sf::Vector2f(5.0f, -50.0f)));

    int plusAGauche = decorations.front()->getPosition().x;
    int plusADroite = decorations.back()->getPosition().x;

    bool keys[1024];

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                keys[sf::Keyboard::Q] = true;
            }
            else
            {
                keys[sf::Keyboard::Q] = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                keys[sf::Keyboard::D] = true;
            }
            else
            {
                keys[sf::Keyboard::D] = false;
            }
        }

        if (keys[sf::Keyboard::D])
        {
            sf::View nouvelleVue = window.getView();
            nouvelleVue.move(5, 0);
            window.setView(nouvelleVue);
        }
        if (keys[sf::Keyboard::Q])
        {
            sf::View nouvelleVue = window.getView();
            nouvelleVue.move(-5, 0);
            window.setView(nouvelleVue);
        }

        while ((window.getView().getCenter().x - (window.getView().getSize().x / 2) - 400) < solGestion.sols[0].position.x)
        {
            solGestion.ajouterGauche();
        }

        while ((window.getView().getCenter().x + (window.getView().getSize().x / 2) + 200) > (solGestion.sols.back().position.x + solGestion.sols.back().getLocalBounds().width))
        {
            solGestion.ajouterDroite();
        }

        while ((window.getView().getCenter().x - (window.getView().getSize().x / 2)) > solGestion.sols[0].position.x + 400)
        {
            solGestion.supprimerGauche();
        }

        while ((window.getView().getCenter().x + (window.getView().getSize().x / 2)) < (solGestion.sols.back().position.x + solGestion.sols.back().getLocalBounds().width - 200))
        {
            solGestion.supprimerDroite();
        }

        while ((window.getView().getCenter().x - (window.getView().getSize().x / 2)) - 600 < plusAGauche)
        {
            unsigned espacement = (rand() % 300) + 150;
            int coteGauche = plusAGauche - espacement;
            plusAGauche = (*(decorations.insert(decorations.begin(), new Arbre(sf::Vector2f(coteGauche, -50.0f)))))->getPosition().x;
        }

        while ((window.getView().getCenter().x + (window.getView().getSize().x / 2)) + 600 > plusADroite)
        {
            unsigned espacement = (rand() % 300) + 150;
            int coteDroit = plusADroite + espacement;
            decorations.push_back(new Arbre(sf::Vector2f(coteDroit, -50.0f)));
            plusADroite = decorations.back()->getPosition().x;
        }

        while ((window.getView().getCenter().x - (window.getView().getSize().x / 2)) - 1200 > plusAGauche)
        {
            plusAGauche = (*(decorations.erase(decorations.begin())))->getPosition().x;
        }

        while ((window.getView().getCenter().x + (window.getView().getSize().x / 2)) + 1200 < plusADroite)
        {
            decorations.pop_back();
            plusADroite = decorations.back()->getPosition().x;
        }

        window.clear(sf::Color(173, 216, 230));

        for (unsigned taille = 0; taille < decorations.size(); taille++)
        {
            window.draw(*(decorations[taille]));
        }

        for (unsigned taille = 0; taille < solGestion.sols.size(); taille++)
        {
            window.draw(solGestion.sols[taille]);
        }

        window.display();
    }

    return 0;
}
