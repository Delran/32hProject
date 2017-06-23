#include "Arbre.hpp"
#include "StaticGestion.hpp"

#include <iostream>

int main()
{
    Arbre::getAtlas();
    Sol::getAtlas();
    Herbe::getAtlas();
    Midground::getAtlas();
    Background::getAtlas();

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Forest", sf::Style::Fullscreen);
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Forest");

    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    StaticGestion staticGestion (sf::Vector2f(0.0f, 750.0f));
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
            for (unsigned taille = 0; taille < staticGestion.backgrounds.size(); taille++)
            {
                staticGestion.backgrounds[taille].move(3, 0);
            }
            for (unsigned taille = 0; taille < staticGestion.midgrounds.size(); taille++)
            {
                staticGestion.midgrounds[taille].move(4, 0);
            }

            for (unsigned taille = 0; taille < decorations.size(); taille++)
            {
                decorations[taille]->move(5, 0);
            }

            for (unsigned taille = 0; taille < staticGestion.sols.size(); taille++)
            {
                staticGestion.sols[taille].move(5, 0);
            }
            for (unsigned taille = 0; taille < staticGestion.herbes.size(); taille++)
            {
                staticGestion.herbes[taille].move(5, 0);
            }
        }
        if (keys[sf::Keyboard::Q])
        {
            for (unsigned taille = 0; taille < staticGestion.backgrounds.size(); taille++)
            {
                staticGestion.backgrounds[taille].move(-3, 0);
            }
            for (unsigned taille = 0; taille < staticGestion.midgrounds.size(); taille++)
            {
                staticGestion.midgrounds[taille].move(-4, 0);
            }

            for (unsigned taille = 0; taille < decorations.size(); taille++)
            {
                decorations[taille]->move(-5, 0);
            }

            for (unsigned taille = 0; taille < staticGestion.sols.size(); taille++)
            {
                staticGestion.sols[taille].move(-5, 0);
            }
            for (unsigned taille = 0; taille < staticGestion.herbes.size(); taille++)
            {
                staticGestion.herbes[taille].move(-5, 0);
            }
        }

        staticGestion.update(window.getSize().x);

        while ((window.getView().getCenter().x - (window.getView().getSize().x / 2)) - 600 < plusAGauche)
        {
            unsigned espacement = (rand() % 300) + 100;
            int coteGauche = plusAGauche - espacement;
            plusAGauche = (*(decorations.insert(decorations.begin(), new Arbre(sf::Vector2f(coteGauche, -50.0f)))))->getPosition().x;
        }

        while ((window.getView().getCenter().x + (window.getView().getSize().x / 2)) + 600 > plusADroite)
        {
            unsigned espacement = (rand() % 300) + 100;
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

        window.clear(sf::Color(153, 196, 210));

        for (unsigned taille = 0; taille < staticGestion.backgrounds.size(); taille++)
        {
            window.draw(staticGestion.backgrounds[taille]);
        }
        for (unsigned taille = 0; taille < staticGestion.midgrounds.size(); taille++)
        {
            window.draw(staticGestion.midgrounds[taille]);
        }

        for (unsigned taille = 0; taille < decorations.size(); taille++)
        {
            window.draw(*(decorations[taille]));
        }

        for (unsigned taille = 0; taille < staticGestion.sols.size(); taille++)
        {
            window.draw(staticGestion.sols[taille]);
        }
        for (unsigned taille = 0; taille < staticGestion.herbes.size(); taille++)
        {
            window.draw(staticGestion.herbes[taille]);
        }

        window.display();
    }

    return 0;
}
