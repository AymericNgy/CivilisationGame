#include "affichable_deprecated.hpp"


//Affichable() : m_positionX(0), m_positionY(0) {this->setTextureFileName();};
// [!] A COMPLETER



void Affichable::getPosition(double &x, double &y) const {
    x = m_positionX; y = m_positionY;

    }


void Affichable::setPosition(double x, double y){
     m_positionX = x; m_positionY = y;

     }

