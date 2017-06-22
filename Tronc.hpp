#include <SFML/Graphics.hpp>

class Tronc : public sf::Sprite
{
private:
    static sf::Texture troncs;

public:
    static void getAtlas();
    Tronc (sf::Vector2f);
    ~Tronc ();
};
