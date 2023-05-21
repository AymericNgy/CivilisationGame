#include "../AffichableOnMap/mine.hpp"
#include "../utile.hpp"
#include "../Commande/extraction_de_puits.hpp"
#include "../Commande/robot_mineur.hpp"



int Mine::nombreActionBonus=0;
int Mine::nombrePvBonus=0;

bool Mine::extractionDePuitsDebloque=false;
bool Mine::robotMineurDebloque=false;
  


int Mine::productionOr=Mine::PRODUCTION_OR_ORIGINE;

const std::string Mine::TEXTURE_FILE_NAME="gold_mine.png";
const std::string Mine::INFO="genere de l'or a chaque tour";
const std::string Mine::NAME="Mine";

const std::string Mine::ICONE_TEXTURE_FILE_NAME="mine_or_icone.png";


const std::string Mine::SOUND_NAME_OF_SELECTION = "mine_selection.wav";

Mine::Mine(Joueur_ptr joueurProprietaire) : Batiment(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Mine::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    if (extractionDePuitsDebloque==false) {
        commandes->push_back(new ExtractionDePuits(this));
    }
    if (extractionDePuitsDebloque==true && robotMineurDebloque==false) {
        commandes->push_back(new RobotMineur(this));
    }
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
    bois = 0;
    nourriture = 0;
    _or = productionOr;
}

void Mine::_commandeExtractionDePuits() {
    productionOr=PRODUCTION_OR_EXCTRACTION_DE_PUITS;
    extractionDePuitsDebloque=true;
}

void Mine::_commandeRobotMineur() {
    productionOr=PRODUCTION_OR_ROBOT_MINEUR;
    robotMineurDebloque=true;
}

std::string Mine::soundNameOfSelection() {
    return SOUND_NAME_OF_SELECTION;
}