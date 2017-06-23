#include <SFML/Graphics.hpp>

#define BACKGROUND_WIDTH 526
#define BACKGROUND_HEIGHT 190

class Background : public sf::Sprite
{
private:
    static sf::Texture backgrounds;

public:
    static void getAtlas();
    Background (sf::Vector2f);
    ~Background ();
};
