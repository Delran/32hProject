#include <SFML/Graphics.hpp>

#define SOL_WIDTH 160
#define SOL_HEIGHT 33

class Sol : public sf::Sprite
{
private:
    static sf::Texture sols;

public:
    static void getAtlas();
    Sol (sf::Vector2f);
    ~Sol ();
};
