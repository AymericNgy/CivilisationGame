#include "faux_tranchante.hpp"
#include "../AffichableOnMap/moulin.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"


const std::string FauxTranchante::TEXTURE_NAME = "technologie_FAUX_TRANCHANTE.png";
const std::string FauxTranchante::INFO="Faux tranchante:\nAugmenter la production de nourriture de tous vos moulins";


FauxTranchante::FauxTranchante(Moulin* moulinPourAction) : CommandeSquare(TEXTURE_NAME,INFO,0,0,PRIX_OR) {
    this->moulinPourAction = moulinPourAction;
}


void FauxTranchante::execute() {
    Joueur_ptr &joueurActif = Jeu::getInstance().getJoueurActif();
    if (this->peutAcheter() && moulinPourAction->getNombreActionRestante()>0) {
        Moulin::_commandeFauxTranchante();
        acheter();
        moulinPourAction->decreaseNombreAction();
        Jeu::getInstance().getJoueurActif()->loadSelectedCase();
    }

}