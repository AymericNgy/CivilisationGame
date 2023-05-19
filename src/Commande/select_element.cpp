#include "select_element.hpp"
#include "commande_square.hpp"
#include "../case.hpp"


const std::string SelectElement::TEXTURE_NAME = "select_element_commande.png";

const std::string SelectElement::INFO = "Choisissez l'une de vos unites presentes sur la case";


SelectElement::SelectElement(Case_ptr casePourAction) : CommandeSquare(TEXTURE_NAME, INFO,0,0,0) {
    this->casePourAction=casePourAction;

}


void SelectElement::execute() {
    
    casePourAction->_commandeSelectElement();

};