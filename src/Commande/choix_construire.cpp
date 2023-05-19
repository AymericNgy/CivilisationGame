#include "choix_construire.hpp"
#include "commande_square.hpp"
#include "../case.hpp"


const std::string ChoixConstuire::TEXTURE_NAME = "construire_commande.png";
const std::string ChoixConstuire::INFO = "Choisissez de construire un batiment";

ChoixConstuire::ChoixConstuire(Case_ptr casePourAction) : CommandeSquare(TEXTURE_NAME, INFO,0,0,0) {
    this->casePourAction=casePourAction;
}


void ChoixConstuire::execute() {
    casePourAction->_commandeConstuire();
};