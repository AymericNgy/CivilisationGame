#include "se_deplacer.hpp"
#include "../AffichableOnMap/interface_se_deplacer.hpp"

const std::string SeDeplacer::TEXTURE_NAME = "commande_valider.png";
const std::string SeDeplacer::INFO = "Valider votre deplacement";

SeDeplacer::SeDeplacer(InterfaceSeDeplacer *elementPourAction) : CommandeSquare(TEXTURE_NAME, INFO,0,0,0) {
    this->elementPourAction=elementPourAction;
}

void SeDeplacer::execute() {
    this->elementPourAction->_commandeSeDeplacer();
}