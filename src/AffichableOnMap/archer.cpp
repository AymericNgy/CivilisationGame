#include "archer.hpp"
#include "../Commande/choix_se_deplacer.hpp"
#include "../Commande/choix_attaquer.hpp"

const std::string Archer::TEXTURE_FILE_NAME = "archer_icone.png";
const std::string Archer::INFO = "degats eleves a distance";
const std::string Archer::NAME ="Archer";

const std::string Archer::ICONE_TEXTURE_FILE_NAME = "archer_icone.png";




int Archer::nombreActionBonus = 0;
int Archer::nombrePvBonus = 0;
float Archer::mombreCaseDeplacementBonus=0;
int Archer::nombreDegatBonus=0;
float Archer::distanceAttaqueBonus=0;




Archer::Archer(Joueur_ptr joueurProprietaire) : Unite(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Archer::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new ChoixSeDeplacer(this)); // car herite de InterfaceSePlacer
    commandes->push_back(new ChoixAttaquer(this)); // car herite de InterfaceAttaquer
    return commandes;

}


void Archer::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Archer::nouveauTour() {
    resetNombreAction();
}