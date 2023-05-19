#include "select_specific_element.hpp"
#include "commande_square.hpp"
#include "../AffichableOnMap/element_joueur.hpp"
#include "../jeu.hpp"
#include  "../hud.hpp"



SelectSpecificElement::SelectSpecificElement(ElementJoueur *elementPourAction) : CommandeSquare(elementPourAction->getIconTextureFileName(), elementPourAction->getName() + " \n" +elementPourAction->getInfo(),0,0,0) {
    this->elementPourAction=elementPourAction;

}


void SelectSpecificElement::execute() {
    Jeu::getInstance().getHud().pushInfoElement(elementPourAction);
};