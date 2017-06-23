#include <SFML/Graphics.hpp>

#define MIDGROUND_WIDTH 500
#define MIDGROUND_HEIGHT 316

class Midground : public sf::Sprite
{
private:
    static sf::Texture midgrounds;

public:
    static void getAtlas();
    Midground (sf::Vector2f);
    ~Midground ();
};
