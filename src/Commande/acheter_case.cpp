#include "acheter_case.hpp"
#include "commande_square.hpp"
#include "../case.hpp"
#include "../jeu.hpp"
#include "../hud.hpp"
#include "../joueur.hpp"


const std::string AcheterCase::TEXTURE_NAME = "acheter_case_commande.png";
const std::string AcheterCase::INFO = "Choisissez d'acheter cette case pour pouvoir y constuire";

AcheterCase::AcheterCase(Case_ptr casePourAction) : CommandeSquare(TEXTURE_NAME, INFO,COUT_ACHAT_BOIS,COUT_ACHAT_NOURRITURE,COUT_ACHAT_OR) {
    this->casePourAction=casePourAction;
}


void AcheterCase::execute() {
    if (peutAcheter()) {
        acheter();
        casePourAction->_commandeAcheterCase();
        Jeu::getInstance().getJoueurActif()->loadSelectedCase();
    } 
};