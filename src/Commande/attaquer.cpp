#include "attaquer.hpp"
#include "../AffichableOnMap/interface_attaquer.hpp"

const std::string Attaquer::TEXTURE_NAME = "commande_valider.png";
const std::string Attaquer::INFO = "Valider votre attaque\nCelle-ci est effectuee sur l'unite ayant le plus de point de vie";


Attaquer::Attaquer(InterfaceAttaquer *elementPourAction) : CommandeSquare(TEXTURE_NAME,INFO,0,0,0){
    this->elementPourAction=elementPourAction;
}


void Attaquer::execute() {
    this->elementPourAction->_commandeAttaquer();
}