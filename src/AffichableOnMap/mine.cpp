#include "mine.hpp"


int Mine::nombreActionBonus=0;
int Mine::nombrePvBonus=0;

int Mine::boisParTourBonus=0;
int Mine::nourritureParTourBonus=0;       
int Mine::orParTourBonus=0;

const std::string Mine::TEXTURE_FILE_NAME="gold_mine.png";
const std::string Mine::INFO="genere de l'or a chaque tour";
const std::string Mine::NAME="Mine";

const std::string Mine::ICONE_TEXTURE_FILE_NAME="mine_or_icone.png";

Mine::Mine(Joueur_ptr joueurProprietaire) : Batiment(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Mine::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    return commandes;
}


void Mine::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Mine::nouveauTour() {
    resetNombreAction();
    creationRessource(); // car implemente l'interface InterfaceCreeRessource
}


void Mine::ressourceParTour(int &bois, int &nourriture, int &_or) {
    bois = BOIS_PAR_TOUR_ORIGINE+boisParTourBonus;
    nourriture = NOURRITURE_PAR_TOUR_ORIGINE+nourritureParTourBonus;
    _or = OR_PAR_TOUR_ORIGINE+orParTourBonus;
}