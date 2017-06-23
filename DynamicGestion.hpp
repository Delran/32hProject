#include <vector>

#include "Arbre.hpp"

class DynamicGestion
{
private:
    void ajouterGauche();
    void ajouterDroite();
    void supprimerGauche();
    void supprimerDroite();

public:
    DynamicGestion (sf::Vector2f);
    ~DynamicGestion ();

    std::vector<sf::Sprite*> elements;

    void update(int);
};
