#include "StaticGestion.hpp"
#include "DynamicGestion.hpp"

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
    DynamicGestion dynamicGestion (sf::Vector2f(0.0f, 0.0f));

    sf::Texture framebuffer;
    framebuffer.create(window.getSize().x, window.getSize().y);

    sf::Shader shader;

    const std::string vertexShader = \
    "void main()" \
    "{" \
      "gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;" \
      "gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;" \
      "gl_FrontColor = gl_Color;" \
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

        "float blue = pixel.r * 0.0 + pixel.g * 0.41 + pixel.b * 0.58;"\
        //"gl_FragColor =  gl_Color * (pixel / 16.0);"
        "vec4 color = gl_Color * (pixel / 16.0);"\
        "gl_FragColor = vec4(color.r*0.70, color.g*0.8, color.b * 1.0, 1.0);"

     "}";
    shader.loadFromMemory(vertexShader, sf::Shader::Vertex);
    shader.loadFromMemory(fragmentShader, sf::Shader::Fragment);

    bool versGauche = false;
    bool versDroite = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                versGauche = true;
                versDroite = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                versGauche = false;
                versDroite = true;
            }
        }

        if (versGauche)
        {
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

        for (unsigned taille = 0; taille < staticGestion.sols.size(); taille++)
        {
            window.draw(staticGestion.sols[taille]);
        }
        for (unsigned taille = 0; taille < staticGestion.herbes.size(); taille++)
        {
            window.draw(staticGestion.herbes[taille]);
        }

        framebuffer.update(window);
        //std::cout << framebuffer.getSize().x << framebuffer.getSize().y << '\n';

        sf::Sprite bufferSprite;
        bufferSprite.setTexture(framebuffer);
        bufferSprite.setTextureRect(sf::IntRect(0, 48, window.getView().getSize().x, window.getView().getSize().y-300));

        bufferSprite.setPosition(sf::Vector2f((window.getView().getCenter().x - (window.getView().getSize().x / 2)), window.getView().getSize().y+128));
        bufferSprite.scale(1, -0.5);
        shader.setParameter("texture", sf::Shader::CurrentTexture);
        window.draw(bufferSprite, &shader);

        window.display();
    }

    return 0;
}
