#include "choix_se_deplacer.hpp"
#include "../AffichableOnMap/interface_se_deplacer.hpp"

const std::string ChoixSeDeplacer::TEXTURE_NAME = "commande_se_deplacer.png";


const std::string ChoixSeDeplacer::INFO = "Choisissez de vous deplacer";


ChoixSeDeplacer::ChoixSeDeplacer(InterfaceSeDeplacer *elementPourAction) : CommandeSquare(TEXTURE_NAME, INFO ,0,0,0) {
    this->elementPourAction=elementPourAction;
}

void ChoixSeDeplacer::execute() {
    this->elementPourAction->_commandeChoixSeDeplacer();
}