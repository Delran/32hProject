#include <vector>

#include "Sol.hpp"
#include "Herbe.hpp"
#include "Midground.hpp"
#include "Background.hpp"

class StaticGestion
{
private:
    void ajouterSolGauche();
    void ajouterSolDroite();
    void supprimerSolGauche();
    void supprimerSolDroite();

    void ajouterMidgroundGauche();
    void ajouterMidgroundDroite();
    void supprimerMidgroundGauche();
    void supprimerMidgroundDroite();

    void ajouterBackgroundGauche();
    void ajouterBackgroundDroite();
    void supprimerBackgroundGauche();
    void supprimerBackgroundDroite();

public:
    StaticGestion (sf::Vector2f);
    ~StaticGestion ();

    std::vector<Sol> sols;
    std::vector<Herbe> herbes;
    std::vector<Midground> midgrounds;
    std::vector<Background> backgrounds;

    void update(int);
};
