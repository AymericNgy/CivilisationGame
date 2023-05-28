#include "lancer_partie.hpp"

#include "../UserInterface/UserInterface.hpp"
#include "../jeu.hpp"


const std::string LancerPartie::TEXTURE_NAME = "parchemin_lancer_partie.png";
const std::string LancerPartie::INFO = "";


;

LancerPartie::LancerPartie() : Commande(Pixel(POSITION_X,POSITION_Y),TEXTURE_NAME,INFO,0,0,0) {




}


void LancerPartie::execute() {
    Jeu::getInstance().lancerPartie();
}