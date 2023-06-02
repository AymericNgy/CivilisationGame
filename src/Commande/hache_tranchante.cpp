#include "hache_tranchante.hpp"
#include "../AffichableOnMap/camp_de_bucheron.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"


const std::string HacheTranchante::TEXTURE_NAME = "technologie_HACHE_TRANCHANTE.png";
const std::string HacheTranchante::INFO="Hache tranchante:\nAugmenter la production de de tous vos camps de bucheron";





HacheTranchante::HacheTranchante(Camp_de_bucheron* campPourAction) : CommandeSquare(TEXTURE_NAME,INFO,0,0,PRIX_OR) {
    this->campPourAction = campPourAction;
}


void HacheTranchante::execute() {
    Joueur_ptr &joueurActif = Jeu::getInstance().getJoueurActif();
    if (this->peutAcheter() && campPourAction->getNombreActionRestante()>0) {
        Camp_de_bucheron::_commandeHacheTranchante();
        acheter();
        campPourAction->decreaseNombreAction();
        Jeu::getInstance().getJoueurActif()->loadSelectedCase();
    }

}