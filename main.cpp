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
        // récupère le pixel dans la texture
        //"vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);"


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

        //"gl_FragColor = (gl_Color * blue)*0.5 + pixel*0.5;"
/*
        "vec2 tc0 = vertTexCoord.st + vec2(-texOffset.s, -texOffset.t);" \
        "vec2 tc1 = vertTexCoord.st + vec2(         0.0, -texOffset.t);"\
        "vec2 tc2 = vertTexCoord.st + vec2(+texOffset.s, -texOffset.t);"\
        "vec2 tc3 = vertTexCoord.st + vec2(-texOffset.s,          0.0);"\
        "vec2 tc4 = vertTexCoord.st + vec2(         0.0,          0.0);"\
        "vec2 tc5 = vertTexCoord.st + vec2(+texOffset.s,          0.0);"\
        "vec2 tc6 = vertTexCoord.st + vec2(-texOffset.s, +texOffset.t);"\
        "vec2 tc7 = vertTexCoord.st + vec2(         0.0, +texOffset.t);"\
        "vec2 tc8 = vertTexCoord.st + vec2(+texOffset.s, +texOffset.t);"\

        "vec4 col0 = texture2D(texture, tc0);"\
        "vec4 col1 = texture2D(texture, tc1);"\
        "vec4 col2 = texture2D(texture, tc2);"\
        "vec4 col3 = texture2D(texture, tc3);"\
        "vec4 col4 = texture2D(texture, tc4);"\
        "vec4 col5 = texture2D(texture, tc5);"\
        "vec4 col6 = texture2D(texture, tc6);"\
        "vec4 col7 = texture2D(texture, tc7);"\
        "vec4 col8 = texture2D(texture, tc8);"\

        "vec4 sum = (1.0 * col0 + 2.0 * col1 + 1.0 * col2 +"\
                    "2.0 * col3 + 4.0 * col4 + 2.0 * col5 +"\
                    "1.0 * col6 + 2.0 * col7 + 1.0 * col8) / 16.0;"\
        "gl_FragColor = vec4(sum.rgb, 1.0) * vertColor;"\
*/
     "}";
    //"gl_FragColor = ((gl_Color * gray) * 0.5) + (pixel * 0.5);"
    shader.loadFromMemory(vertexShader, sf::Shader::Vertex);

    //shader.setParameter("texture", framebuffer);
    shader.loadFromMemory(fragmentShader, sf::Shader::Fragment);


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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                keys[sf::Keyboard::Z] = true;
            }
            else
            {
                keys[sf::Keyboard::Z] = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                keys[sf::Keyboard::S] = true;
            }
            else
            {
                keys[sf::Keyboard::S] = false;
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
        if (keys[sf::Keyboard::Z])
        {
            sf::View nouvelleVue = window.getView();
            nouvelleVue.move(0, -5);
            window.setView(nouvelleVue);
        }
        if (keys[sf::Keyboard::S])
        {
            sf::View nouvelleVue = window.getView();
            nouvelleVue.move(0, 5);
            window.setView(nouvelleVue);
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


        framebuffer.update(window);
        //std::cout << framebuffer.getSize().x << framebuffer.getSize().y << '\n';

        sf::Sprite bufferSprite;
        bufferSprite.setTexture(framebuffer);
        bufferSprite.setTextureRect(sf::IntRect(0, 110, window.getView().getSize().x, window.getView().getSize().y-200));

        bufferSprite.setPosition(sf::Vector2f((window.getView().getCenter().x - (window.getView().getSize().x / 2)), window.getView().getSize().y+260));
        bufferSprite.scale(1, -0.5);
        shader.setParameter("texture", sf::Shader::CurrentTexture);
        window.draw(bufferSprite, &shader);

        window.display();
    }

    return 0;
}
