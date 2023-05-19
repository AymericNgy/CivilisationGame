#include "choix_attaquer.hpp"
#include "../AffichableOnMap/interface_attaquer.hpp"


const std::string ChoixAttaquer::TEXTURE_NAME = "choix_attaquer.png";


const std::string ChoixAttaquer::INFO = "Choisissez d'attaquer";

ChoixAttaquer::ChoixAttaquer(InterfaceAttaquer *elementPourAction) : CommandeSquare(TEXTURE_NAME,INFO,0,0,0) {
    this->elementPourAction=elementPourAction;
}
void ChoixAttaquer::execute() {
    this->elementPourAction->_commandeChoixAttaquer();
}
