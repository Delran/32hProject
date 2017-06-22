#include <vector>

#include "Sol.hpp"

class SolGestion
{
private:

public:
    SolGestion (sf::Vector2f);
    ~SolGestion ();

    void ajouterGauche();
    void ajouterDroite();
    void supprimerGauche();
    void supprimerDroite();

    std::vector<Sol> sols;
};
