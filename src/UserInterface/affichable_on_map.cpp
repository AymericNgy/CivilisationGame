#include "affichable_on_map.hpp"
#include "../jeu.hpp"

AffichableOnMap::AffichableOnMap(CasePosition casePosition, int couche, std::string textureName) : sprite(textureName,couche,true) {

    this->plateau = &Jeu::getInstance().getPlateau();
    this->sprite.setCasePosition(casePosition);
    

    this->plateau->addElement(casePosition, this); 

}


AffichableOnMap::AffichableOnMap(Plateau &plateau, CasePosition casePosition, int couche, std::string textureName): sprite(textureName,couche,true) {
    this->plateau = &plateau;
    this->sprite.setCasePosition(casePosition);
    this->plateau->addElement(casePosition, this); 
}


AffichableOnMap::~AffichableOnMap() {
    std::cout << "debut ~AffichableOnMap()" << std::endl;
    this->plateau->removeElement(this->getCasePosition(),this);
    std::cout << "fin ~AffichableOnMap()"<< std::endl;
}

void AffichableOnMap::moveToPosition(CasePosition casePosition) {
   this->plateau->moveElement(this->getCasePosition(),casePosition,this);
    sprite.setCasePosition(casePosition);
}

void AffichableOnMap::setTextures(std::string textureName) {
    sprite.setTexturesUI(textureName);
}