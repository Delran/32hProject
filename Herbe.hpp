#include <SFML/Graphics.hpp>

#define HERBE_WIDTH 100
#define HERBE_HEIGHT 16

class Herbe : public sf::Sprite
{
private:
    static sf::Texture herbes;

public:
    static void getAtlas();
    Herbe (sf::Vector2f);
    ~Herbe ();
};
