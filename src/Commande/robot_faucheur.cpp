#include "robot_faucheur.hpp"
#include "../AffichableOnMap/moulin.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"


const std::string RobotFaucheur::TEXTURE_NAME = "technologie_ROBOT_FAUCHEUR.png";
const std::string RobotFaucheur::INFO="Robot faucheur:\nAugmenter la production de nourriture de tous vos moulins";





RobotFaucheur::RobotFaucheur(Moulin* moulinPourAction) : CommandeSquare(TEXTURE_NAME,INFO,0,0,PRIX_OR) {
    this->moulinPourAction = moulinPourAction;
}


void RobotFaucheur::execute() {
    Joueur_ptr &joueurActif = Jeu::getInstance().getJoueurActif();
    if (this->peutAcheter() && moulinPourAction->getNombreActionRestante()>0) {
        Moulin::_commandeRobotFaucheur();
        acheter();
        moulinPourAction->decreaseNombreAction();
        Jeu::getInstance().getJoueurActif()->loadSelectedCase();
    }

}