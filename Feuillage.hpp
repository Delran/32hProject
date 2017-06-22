#include <SFML/Graphics.hpp>

class Feuillage : public sf::Sprite
{
private:
    static sf::Texture feuillages;

public:
    static void getAtlas();
    Feuillage (sf::Vector2f);
    ~Feuillage ();
};
