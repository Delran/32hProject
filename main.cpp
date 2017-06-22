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

        unsigned typeDecoration;
        unsigned nbRepetitions = 0;
        unsigned espacement;

        while ((window.getView().getCenter().x - (window.getView().getSize().x / 2)) - 600 < plusAGauche)
        {
            espacement = (rand() % 200) + 100;

            int coteGauche = plusAGauche - espacement;
            plusAGauche = (*(decorations.insert(decorations.begin(), new Arbre(sf::Vector2f(coteGauche, -50.0f)))))->getPosition().x;
        }

        /*nbRepetitions = 0;

        while ((window.getView().getCenter().x + (window.getView().getSize().x / 2)) > (decorations.back()->getPosition().x + decorations.back()->getLocalBounds().width))
        {
            if (nbRepetitions == 0)
            {
                typeDecoration = rand() % 100;
            }

            if (typeDecoration < 90)
            {
                int positionGauche = decorations.back()->getPosition().x + (rand() % 200) + 200;
                decorations.push_back(new Arbre(sf::Vector2f(positionGauche, -50.0f)));
                nbRepetitions = (rand() % 15) + 5;
            }
        }*/

        while ((window.getView().getCenter().x - (window.getView().getSize().x / 2)) > plusAGauche + 900)
        {
            plusAGauche = (*(decorations.erase(decorations.begin())))->getPosition().x;
        }

        /*while ((window.getView().getCenter().x + (window.getView().getSize().x / 2)) < (decorations.back()->getPosition().x + decorations.back()->getLocalBounds().width))
        {
            decorations.pop_back();
        }*/

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
