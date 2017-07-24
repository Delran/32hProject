#include <SFML/Graphics.hpp>

class Deer : public sf::Sprite
{
public:
    Deer(sf::Vector2f);
    ~Deer();
    static void getAtlas();
    void animate();
    void eatLoop();
    void delUpdateRight(int x);
    void delUpdateLeft();
    bool toDelete();

private:
    static sf::Texture idle, idleLook, eating, eatingEnd, startEating;
    unsigned long loop = 0;
    bool anim = 0, deletable = 0;

};
