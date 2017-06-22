#include <SFML/Graphics.hpp>

class Arbre : public sf::Sprite
{
private:
    static sf::Texture arbres;

public:
    static void getAtlas();
    Arbre (sf::Vector2f);
    ~Arbre ();
};
