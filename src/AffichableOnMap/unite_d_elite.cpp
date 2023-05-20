#include "unite_d_elite.hpp"
#include "../Commande/choix_se_deplacer.hpp"
#include "../Commande/choix_attaquer.hpp"

const std::string unite_d_elite::TEXTURE_FILE_NAME = "unite_d_elite_icone.png";
const std::string unite_d_elite::INFO = "degats magiques tres eleves a distance";
const std::string unite_d_elite::NAME ="Unite_d_elite";

const std::string unite_d_elite::ICONE_TEXTURE_FILE_NAME = "unite_d_elite_icone.png";




int unite_d_elite::nombreActionBonus = 0;
int unite_d_elite::nombrePvBonus = 0;
float unite_d_elite::mombreCaseDeplacementBonus=0;
int unite_d_elite::nombreDegatBonus=0;
float unite_d_elite::distanceAttaqueBonus=0;




unite_d_elite::unite_d_elite(Joueur_ptr joueurProprietaire) : Unite(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr unite_d_elite::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new ChoixSeDeplacer(this)); // car herite de InterfaceSePlacer
    commandes->push_back(new ChoixAttaquer(this)); // car herite de InterfaceAttaquer
    return commandes;

}


void unite_d_elite::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void unite_d_elite::nouveauTour() {
    resetNombreAction();
}