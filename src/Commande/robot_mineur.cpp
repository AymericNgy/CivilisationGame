#include "robot_mineur.hpp"
#include "../AffichableOnMap/mine.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"


const std::string RobotMineur::TEXTURE_NAME = "technologie_robot_mineur.png";
const std::string RobotMineur::INFO="Robot mineur:\nAugmenter la production d'or de toutes vos mines";





RobotMineur::RobotMineur( Mine *minePourAction) : CommandeSquare(TEXTURE_NAME,INFO,0,0,PRIX_OR) {
    this->minePourAction = minePourAction;
}


void RobotMineur::execute() {
    Joueur_ptr &joueurActif = Jeu::getInstance().getJoueurActif();
    if (this->peutAcheter() && minePourAction->getNombreActionRestante()>0) {
        Mine::_commandeRobotMineur();
        acheter();
        minePourAction->decreaseNombreAction();
        Jeu::getInstance().getJoueurActif()->loadSelectedCase();
    }

}