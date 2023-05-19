#include "cavalier.hpp"
#include "../Commande/choix_se_deplacer.hpp"
#include "../Commande/choix_attaquer.hpp"

const std::string Cavalier::TEXTURE_FILE_NAME = "cavalier_icone.png";
const std::string Cavalier::INFO = "vitesse de déplacement très élevée";
const std::string Cavalier::NAME ="Cavalier";

const std::string Cavalier::ICONE_TEXTURE_FILE_NAME = "cavalier_icone.png";




int Cavalier::nombreActionBonus = 0;
int Cavalier::nombrePvBonus = 0;
float Cavalier::mombreCaseDeplacementBonus=0;
int Cavalier::nombreDegatBonus=0;
float Cavalier::distanceAttaqueBonus=0;




Cavalier::Cavalier(Joueur_ptr joueurProprietaire) : Unite(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Cavalier::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new ChoixSeDeplacer(this)); // car herite de InterfaceSePlacer
    commandes->push_back(new ChoixAttaquer(this)); // car herite de InterfaceAttaquer
    return commandes;

}


void Cavalier::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Cavalier::nouveauTour() {
    resetNombreAction();
}