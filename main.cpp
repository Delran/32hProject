#include "StaticGestion.hpp"
#include "DynamicGestion.hpp"
#include "Deer.hpp"

#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
    sf::Music music;
    std::string musicPath = "music.ogg";
    if (!music.openFromFile(musicPath))
    {
        std::cout << "Fail loading music : " << musicPath << "." << std::endl;
    }
    music.play();
    music.setVolume(50);
    music.setLoop(true);

    Arbre::getAtlas();
    Sol::getAtlas();
    Herbe::getAtlas();
    Midground::getAtlas();
    Background::getAtlas();
    Deer::getAtlas();

    srand(time(NULL));

    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(videoMode.width, videoMode.height), "Forest", sf::Style::Fullscreen);

    window.setVerticalSyncEnabled(true);

    StaticGestion staticGestion (sf::Vector2f(0.0f, 750.0f));
    DynamicGestion dynamicGestion (sf::Vector2f(0.0f, 0.0f));

    sf::Texture frameTexture;
    frameTexture.create(videoMode.width, videoMode.height);

    sf::Sprite reflectionSprite;
    reflectionSprite.scale(1, -0.48);
    reflectionSprite.setPosition(0, videoMode.height);

    std::vector<Deer> deers;

    int compteur = 0;

    sf::Shader shader;

    const std::string vertexShader = \
    "void main()" \
    "{" \
      "gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;" \
      "gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;" \
    "}";

    const std::string fragmentShader = \
    "uniform sampler2D texture;" \

    "void main()" \
    "{" \
        "vec2 offx = vec2(0.0045, 0.0);"\
        "vec2 offy = vec2(0.0, 0.003);"\

        "vec4 pixel = texture2D(texture, gl_TexCoord[0].xy)               * 4.0 +"\
                    "texture2D(texture, gl_TexCoord[0].xy - offx)        * 2.0 +"\
                    "texture2D(texture, gl_TexCoord[0].xy + offx)        * 2.0 +"\
                    "texture2D(texture, gl_TexCoord[0].xy - offy)        * 2.0 +"\
                    "texture2D(texture, gl_TexCoord[0].xy + offy)        * 2.0 +"\
                    "texture2D(texture, gl_TexCoord[0].xy - offx - offy) * 1.0 +"\
                    "texture2D(texture, gl_TexCoord[0].xy - offx + offy) * 1.0 +"\
                    "texture2D(texture, gl_TexCoord[0].xy + offx - offy) * 1.0 +"\
                    "texture2D(texture, gl_TexCoord[0].xy + offx + offy) * 1.0;"\
        "vec4 color = pixel / 16.0;"\

        "gl_FragColor = vec4(color.r*0.6, color.g*0.8, color.b * 1.0, 1.0);"\
    "}";
    shader.loadFromMemory(vertexShader, sf::Shader::Vertex);
    shader.loadFromMemory(fragmentShader, sf::Shader::Fragment);

    bool versGauche = false;
    bool versDroite = false;

    bool allaitGauche = false;
    bool allaitDroite = false;

    bool spaceLock = false;

    bool facing = false;

    while (window.isOpen())
    {
        //std::cout << compteur << '\n';
        if (compteur > 350)
        {
            compteur = 0;
            unsigned int percent = rand()%100;
            if (percent > 56)
            {
                int x;
                if (versGauche)
                {
                    x = -150;
                }
                else
                {
                    x = window.getView().getSize().x + 150;
                }
                deers.push_back(Deer(sf::Vector2f(x, 668)));

                if (facing)
                    deers.back().scale(-1, 1);
                facing = !facing;
            }
        }


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                versGauche = true;
                allaitGauche = true;
                allaitDroite = false;
                versDroite = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                versGauche = false;
                allaitGauche = false;
                allaitDroite = true;
                versDroite = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !spaceLock)
            {
                spaceLock = true;

                if (versGauche || versDroite)
                {
                    versGauche = false;
                    versDroite = false;
                }
                else
                {
                    versGauche = allaitGauche;
                    versDroite = allaitDroite;
                }
            }
            else
            {
                spaceLock = false;
            }
        }

        if (versGauche)
        {
            compteur++;
            for (unsigned taille = 0; taille < staticGestion.backgrounds.size(); taille++)
            {
                staticGestion.backgrounds[taille].move(1, 0);
            }
            for (unsigned taille = 0; taille < staticGestion.midgrounds.size(); taille++)
            {
                staticGestion.midgrounds[taille].move(2.5, 0);
            }

            for (unsigned taille = 0; taille < dynamicGestion.elements.size(); taille++)
            {
                dynamicGestion.elements[taille]->move(3.5, 0);
            }
            for (unsigned taille = 0; taille < deers.size(); taille++)
            {
                deers[taille].move(3.5, 0);
                deers[taille].delUpdateLeft();
                if (deers[taille].toDelete())
                    deers.erase(deers.begin()+taille);

            }
            for (unsigned taille = 0; taille < staticGestion.sols.size(); taille++)
            {
                staticGestion.sols[taille].move(3.5, 0);
            }
            for (unsigned taille = 0; taille < staticGestion.herbes.size(); taille++)
            {
                staticGestion.herbes[taille].move(3.5, 0);
            }
        }
        else if (versDroite)
        {
            compteur++;
            for (unsigned taille = 0; taille < staticGestion.backgrounds.size(); taille++)
            {
                staticGestion.backgrounds[taille].move(-1, 0);
            }
            for (unsigned taille = 0; taille < staticGestion.midgrounds.size(); taille++)
            {
                staticGestion.midgrounds[taille].move(-2.5, 0);
            }

            for (unsigned taille = 0; taille < dynamicGestion.elements.size(); taille++)
            {
                dynamicGestion.elements[taille]->move(-3.5, 0);
            }
            for (unsigned taille = 0; taille < deers.size(); taille++)
            {
                deers[taille].move(-3.5, 0);
                deers[taille].delUpdateRight(window.getView().getSize().x);
                if (deers[taille].toDelete())
                    deers.erase(deers.begin()+taille);
            }
            for (unsigned taille = 0; taille < staticGestion.sols.size(); taille++)
            {
                staticGestion.sols[taille].move(-3.5, 0);
            }
            for (unsigned taille = 0; taille < staticGestion.herbes.size(); taille++)
            {
                staticGestion.herbes[taille].move(-3.5, 0);
            }
        }

        window.clear(sf::Color(153, 196, 210));

        staticGestion.update(window.getSize().x);
        dynamicGestion.update(window.getSize().x);

        for (unsigned taille = 0; taille < staticGestion.backgrounds.size(); taille++)
        {
            window.draw(staticGestion.backgrounds[taille]);
        }
        for (unsigned taille = 0; taille < staticGestion.midgrounds.size(); taille++)
        {
            window.draw(staticGestion.midgrounds[taille]);
        }

        for (unsigned taille = 0; taille < dynamicGestion.elements.size(); taille++)
        {
            window.draw(*(dynamicGestion.elements[taille]));
        }
        for (unsigned taille = 0; taille < deers.size(); taille++)
        {
            deers[taille].animate();
            window.draw(deers[taille]);
        }
        for (unsigned taille = 0; taille < staticGestion.sols.size(); taille++)
        {
            window.draw(staticGestion.sols[taille]);
        }
        for (unsigned taille = 0; taille < staticGestion.herbes.size(); taille++)
        {
            window.draw(staticGestion.herbes[taille]);
        }

        frameTexture.update(window);

        reflectionSprite.setTexture(frameTexture);
        reflectionSprite.setTextureRect(sf::IntRect(0, videoMode.height * 0.25, videoMode.width, videoMode.height * 0.5));

        window.draw(reflectionSprite, &shader);

        window.display();
    }

    return 0;
}
