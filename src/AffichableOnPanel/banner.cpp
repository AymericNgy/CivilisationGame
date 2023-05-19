#include "banner.hpp"
#include "../UserInterface/UserInterface.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"

const std::string Banner::TEXTURE_NAME = "banner.png";



const int Banner::POSITION_X = UserInterface::WINDOW_WIDTH-Banner::WIDTH- 20; 
const int Banner::POSITION_Y = 20;

Banner::Banner() : AffichableOnPanel(Pixel(POSITION_X,POSITION_Y),COUCHE,TEXTURE_NAME) {
    update();
}


void Banner::update() {
    Joueur_ptr joueurActif = Jeu::getInstance().getJoueurActif();
    this->sprite->setColor(joueurActif->getCouleur());

}