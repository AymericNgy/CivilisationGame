#include "../AffichableOnMap/moulin.hpp"
#include "../utile.hpp"
#include "../Commande/faux_tranchante.hpp"
#include "../Commande/robot_faucheur.hpp"



int Moulin::nombreActionBonus=0;
int Moulin::nombrePvBonus=0;

bool Moulin::fauxTranchanteDebloque=false;
bool Moulin::robotFaucheurDebloque=false;
  


int Moulin::productionNourriture=Moulin::PRODUCTION_NOURRITURE_ORIGINE;

const std::string Moulin::TEXTURE_FILE_NAME="moulin.png";
const std::string Moulin::INFO="genere de la nourriture a chaque tour";
const std::string Moulin::NAME="Moulin";

const std::string Moulin::ICONE_TEXTURE_FILE_NAME="moulin_icone.png";


const std::string Moulin::SOUND_NAME_OF_SELECTION = "moulin_selection.wav";

Moulin::Moulin(Joueur_ptr joueurProprietaire) : Batiment(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Moulin::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    if (fauxTranchanteDebloque==false) {
        commandes->push_back(new FauxTranchante(this));
    }
    if (fauxTranchanteDebloque==true && robotFaucheurDebloque==false) {
        commandes->push_back(new RobotFaucheur(this));
    }
    return commandes;
}


void Moulin::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Moulin::nouveauTour() {
    resetNombreAction();
    creationRessource(); // car implemente l'interface InterfaceCreeRessource
}


void Moulin::ressourceParTour(int &bois, int &nourriture, int &_or) {
    bois = 0;
    nourriture = productionNourriture;
    _or = 0;
}

void Moulin::_commandeFauxTranchante() {
    productionNourriture=PRODUCTION_NOURRITURE_FAUX_TRANCHANTE;
    fauxTranchanteDebloque=true;
}

void Moulin::_commandeRobotFaucheur() {
    productionNourriture=PRODUCTION_NOURRITURE_ROBOT_FAUCHEUR;
    robotFaucheurDebloque=true;
}

std::string Moulin::soundNameOfSelection() {
    return SOUND_NAME_OF_SELECTION;
}