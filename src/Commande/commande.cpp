#include "commande.hpp"
#include "../UserInterface/affichable_on_panel.hpp"
#include "../UserInterface/UserInterface.hpp"
#include "../UserInterface/SpriteForUI.hpp"
#include "../joueur.hpp"
#include "../jeu.hpp"




// Commande::Commande(Pixel position, std::string texturePathName, std::string info) : info(info) , AffichableOnPanel(position,COUCHE,texturePathName) {
//     prix_bois=0;
//     prix_nourriture=0;
//     prix_or=0;


//     UserInterface &ui = UserInterface::getInstance();
//     ui.addCommande(this);

// };

Commande::Commande(Pixel position, std::string texturePathName, std::string info, int bois, int nourriture, int _or) : info(info) , AffichableOnPanel(position,COUCHE,texturePathName) {
    prix_bois=bois;
    prix_nourriture=nourriture;
    prix_or=_or;
    UserInterface &ui = UserInterface::getInstance();
    ui.addCommande(this);

};



std::string Commande::getInfo() const {
    return info;
}

Commande::~Commande() {
    UserInterface &ui = UserInterface::getInstance();
    ui.removeCommande(this);

}

bool Commande::pixelIsOn(int x, int y) const{
    return sprite->getGlobalBounds().contains(sf::Vector2f(x,y));
}


bool Commande::peutAcheter() {
    Joueur_ptr joueur_actif = Jeu::getInstance().getJoueurActif();
    return joueur_actif->peutDecreaseBois(prix_bois)&& joueur_actif->peutDecreaseNourriture(prix_nourriture) && joueur_actif->peutDecreaseOr(prix_or);
}

bool Commande::acheter() {
    Joueur_ptr joueur_actif = Jeu::getInstance().getJoueurActif();
    if (peutAcheter()) {
        joueur_actif->decreaseBois(prix_bois);
        joueur_actif->decreaseNourriture(prix_nourriture);
        joueur_actif->decreaseOr(prix_or);
        return true;
    }
    return false;
}


void Commande::prix(int &bois, int &nourriture, int &_or) { 
    bois=prix_bois;
    nourriture=prix_nourriture;
    _or=prix_or;
}