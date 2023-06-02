#include "robot_tronconneuse.hpp"
#include "../AffichableOnMap/camp_de_bucheron.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"


const std::string RobotTronconneuse::TEXTURE_NAME = "technologie_ROBOT_TRONCONNEUSE.png";
const std::string RobotTronconneuse::INFO="Robot tronconneuse:\nAugmenter la production de bois de tous vos camps de bucherons";





RobotTronconneuse::RobotTronconneuse(Camp_de_bucheron* campPourAction) : CommandeSquare(TEXTURE_NAME,INFO,0,0,PRIX_OR) {
    this->campPourAction = campPourAction;
}


void RobotTronconneuse::execute() {
    Joueur_ptr &joueurActif = Jeu::getInstance().getJoueurActif();
    if (this->peutAcheter() && campPourAction->getNombreActionRestante()>0) {
        Camp_de_bucheron::_commandeRobotTronconneuse();
        acheter();
        campPourAction->decreaseNombreAction();
        Jeu::getInstance().getJoueurActif()->loadSelectedCase();
    }

}