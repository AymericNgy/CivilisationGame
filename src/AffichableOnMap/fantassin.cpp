#include "fantassin.hpp"
#include "../Commande/choix_se_deplacer.hpp"
#include "../Commande/choix_attaquer.hpp"

const std::string Fantassin::TEXTURE_FILE_NAME = "fantassin_icone.png";
const std::string Fantassin::INFO = "efficace contre la cavalerie";
const std::string Fantassin::NAME ="Fantassin";

const std::string Fantassin::ICONE_TEXTURE_FILE_NAME = "fantassin_icone.png";




int Fantassin::nombreActionBonus = 0;
int Fantassin::nombrePvBonus = 0;
float Fantassin::mombreCaseDeplacementBonus=0;
int Fantassin::nombreDegatBonus=0;
float Fantassin::distanceAttaqueBonus=0;

const int Fantassin::COUT_ACHAT_BOIS=0;
const int Fantassin::COUT_ACHAT_NOURRITURE=25;
const int Fantassin::COUT_ACHAT_OR=5;


Fantassin::Fantassin(Joueur_ptr joueurProprietaire) : Unite(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Fantassin::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new ChoixSeDeplacer(this));
    commandes->push_back(new ChoixAttaquer(this));
    return commandes;

}


void Fantassin::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Fantassin::nouveauTour() {
    resetNombreAction();
}