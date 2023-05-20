#include "engin_de_siege.hpp"
#include "../Commande/choix_se_deplacer.hpp"
#include "../Commande/choix_attaquer.hpp"

const std::string EnginDeSiege::TEXTURE_FILE_NAME = "engindesiege_icone.png";
const std::string EnginDeSiege::INFO = "degats tres eleves sur les batiments";
const std::string EnginDeSiege::NAME ="engin de siege";

const std::string EnginDeSiege::ICONE_TEXTURE_FILE_NAME = "engindesiege_icone.png";




int EnginDeSiege::nombreActionBonus = 0;
int EnginDeSiege::nombrePvBonus = 0;
float EnginDeSiege::mombreCaseDeplacementBonus=0;
int EnginDeSiege::nombreDegatBonus=0;
float EnginDeSiege::distanceAttaqueBonus=0;




EnginDeSiege::EnginDeSiege(Joueur_ptr joueurProprietaire) : Unite(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr EnginDeSiege::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new ChoixSeDeplacer(this)); // car herite de InterfaceSePlacer
    commandes->push_back(new ChoixAttaquer(this)); // car herite de InterfaceAttaquer
    return commandes;

}


void EnginDeSiege::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void EnginDeSiege::nouveauTour() {
    resetNombreAction();
}