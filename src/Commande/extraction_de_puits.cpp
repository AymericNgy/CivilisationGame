#include "extraction_de_puits.hpp"
#include "../AffichableOnMap/mine.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"


const std::string ExtractionDePuits::TEXTURE_NAME = "technologie_extraction_de_puits.png";
const std::string ExtractionDePuits::INFO="Extraction de puits:\nAugmenter la production d'or de toutes vos mines";





ExtractionDePuits::ExtractionDePuits( Mine *minePourAction) : CommandeSquare(TEXTURE_NAME,INFO,0,0,PRIX_OR) {
    this->minePourAction = minePourAction;
}


void ExtractionDePuits::execute() {
    Joueur_ptr &joueurActif = Jeu::getInstance().getJoueurActif();
    if (this->peutAcheter() && minePourAction->getNombreActionRestante()>0) {
        Mine::_commandeExtractionDePuits();
        acheter();
        minePourAction->decreaseNombreAction();
        Jeu::getInstance().getJoueurActif()->loadSelectedCase();
    }

}