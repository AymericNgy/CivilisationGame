#include "marque.hpp"
#include "../utile.hpp"
#include "../joueur.hpp"

const std::string Marque::OVER_TEXTURE_NAME = "hexagone_marque_over.png";
const std::string Marque::SELECT_TEXTURE_NAME = "hexagone_marque_select.png";
const std::string Marque::CIRCLE_TEXTURE_NAME = "hexagone_marque_circle.png";
const std::string Marque::PROPRIETAIRE_TEXTURE_NAME = "mark_proprietaire_blanche.png";


Marque::Marque(TYPE_MARQUE typeMarque,Plateau &plateau) : AffichableOnMap(plateau,CasePosition(0,0),getCouche(typeMarque),UserInterface::TRANSPARENCY_TEXTURE_NAME) {
    switch (typeMarque)
    {
        case OVER:
            this->setTextures(OVER_TEXTURE_NAME);
            break;
        
        case SELECT:
            this->setTextures(SELECT_TEXTURE_NAME);
            break;

        case CIRCLE:
            this->setTextures(CIRCLE_TEXTURE_NAME);
            break;
        
        default:
            Utile::erreur(__func__,"Type de Marque non implemente");    
            break;
    }
    
}

Marque::Marque(Joueur_ptr joueurProprietaire,Plateau &plateau, CasePosition position) : AffichableOnMap(plateau,position,COUCHE_MARQUE_PROPRIETAIRE,UserInterface::TRANSPARENCY_TEXTURE_NAME) {
    this->setTextures(PROPRIETAIRE_TEXTURE_NAME);
    this->setColor(joueurProprietaire->getCouleur());
}





int Marque::getCouche(TYPE_MARQUE typeMarque) {
    switch (typeMarque)
    {
        case OVER:
            return COUCHE_MARQUE_OVER;
        
        case SELECT:
            return COUCHE_MARQUE_SELECT;

        case CIRCLE:
            return COUCHE_MARQUE_CIRCLE;
        
        default:
            return 0;
    }
}