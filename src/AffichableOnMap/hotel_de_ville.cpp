#include "hotel_de_ville.hpp"
#include "../Commande/choix_attaquer.hpp"


const std::string HotelDeVille::TEXTURE_FILE_NAME = "hotel_de_ville.png";
const std::string HotelDeVille::INFO = "Batiment a proteger pour ne pas perdre la partie";
const std::string HotelDeVille::NAME ="Hotel de ville";

const std::string HotelDeVille::ICONE_TEXTURE_FILE_NAME = "hotel_de_ville_icone.png";




int HotelDeVille::nombreActionBonus = 0;
int HotelDeVille::nombrePvBonus = 0;
int HotelDeVille::boisParTourBonus=0;
int HotelDeVille::nourritureParTourBonus=0;       
int HotelDeVille::orParTourBonus=0;
int HotelDeVille::nombreDegatBonus=0;
float HotelDeVille::distanceAttaqueBonus=0;





HotelDeVille::HotelDeVille(Joueur_ptr joueurProprietaire) : Batiment(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr HotelDeVille::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new ChoixAttaquer(this)); // car herite de InterfaceAttaquer
    return commandes;
}


void HotelDeVille::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void HotelDeVille::nouveauTour() {
    resetNombreAction();
    creationRessource(); // car implemente l'interface InterfaceCreeRessource
}


void HotelDeVille::ressourceParTour(int &bois, int &nourriture, int &_or) {
    bois = BOIS_PAR_TOUR_ORIGINE+boisParTourBonus;
    nourriture = NOURRITURE_PAR_TOUR_ORIGINE+nourritureParTourBonus;
    _or = OR_PAR_TOUR_ORIGINE+orParTourBonus;
}