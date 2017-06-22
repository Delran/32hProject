#include <SFML/Graphics.hpp>

class Sol : public sf::Sprite
{
private:
    static sf::Texture sols;

public:
    static void getAtlas();
    Sol (sf::Vector2f);
    ~Sol ();
    
    sf::Vector2f position;
};
