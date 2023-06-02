#include "../AffichableOnMap/camp_de_bucheron.hpp"
#include "../utile.hpp"
#include "../Commande/hache_tranchante.hpp"
#include "../Commande/robot_tronconneuse.hpp"



int Camp_de_bucheron::nombreActionBonus=0;
int Camp_de_bucheron::nombrePvBonus=0;

bool Camp_de_bucheron::hacheTranchanteDebloque=false;
bool Camp_de_bucheron::robotTronconneuseDebloque=false;
  


int Camp_de_bucheron::productionBois=Camp_de_bucheron::PRODUCTION_BOIS_ORIGINE;

const std::string Camp_de_bucheron::TEXTURE_FILE_NAME="camp_de_bucheron.png";
const std::string Camp_de_bucheron::INFO="genere du bois a chaque tour";
const std::string Camp_de_bucheron::NAME="Camp de bucheron";

const std::string Camp_de_bucheron::ICONE_TEXTURE_FILE_NAME="camp_de_bucheron_icone.png";


const std::string Camp_de_bucheron::SOUND_NAME_OF_SELECTION = "camp_bucheron_selection.wav";

Camp_de_bucheron::Camp_de_bucheron(Joueur_ptr joueurProprietaire) : Batiment(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Camp_de_bucheron::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    if (hacheTranchanteDebloque==false) {
        commandes->push_back(new HacheTranchante (this));
    }
    if (hacheTranchanteDebloque==true && robotTronconneuseDebloque==false) {
        commandes->push_back(new RobotTronconneuse(this));
    }
    return commandes;
}


void Camp_de_bucheron::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Camp_de_bucheron::nouveauTour() {
    resetNombreAction();
    creationRessource(); // car implemente l'interface InterfaceCreeRessource
}


void Camp_de_bucheron::ressourceParTour(int &bois, int &nourriture, int &_or) {
    bois = productionBois;
    nourriture = 0;
    _or = 0;
}

void Camp_de_bucheron::_commandeHacheTranchante() {
    productionBois=PRODUCTION_BOIS_HACHE_TRANCHANTE;
    hacheTranchanteDebloque=true;
}

void Camp_de_bucheron::_commandeRobotTronconneuse() {
    productionBois=PRODUCTION_BOIS_ROBOT_TRONCONNEUSE;
    robotTronconneuseDebloque=true;
}

std::string Camp_de_bucheron::soundNameOfSelection() {
    return SOUND_NAME_OF_SELECTION;
}