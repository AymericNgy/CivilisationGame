#include "mage.hpp"
#include "../Commande/choix_se_deplacer.hpp"
#include "../Commande/choix_attaquer.hpp"

const std::string Mage::TEXTURE_FILE_NAME = "mage_icone.png";
const std::string Mage::INFO = "degats magiques tres eleves a distance";
const std::string Mage::NAME ="Mage";

const std::string Mage::ICONE_TEXTURE_FILE_NAME = "mage_icone.png";




int Mage::nombreActionBonus = 0;
int Mage::nombrePvBonus = 0;
float Mage::mombreCaseDeplacementBonus=0;
int Mage::nombreDegatBonus=0;
float Mage::distanceAttaqueBonus=0;




Mage::Mage(Joueur_ptr joueurProprietaire) : Unite(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Mage::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new ChoixSeDeplacer(this)); // car herite de InterfaceSePlacer
    commandes->push_back(new ChoixAttaquer(this)); // car herite de InterfaceAttaquer
    return commandes;

}


void Mage::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Mage::nouveauTour() {
    resetNombreAction();
}