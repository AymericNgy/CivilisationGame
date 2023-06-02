#include "chateau.hpp"
#include "../Commande/creer_element.hpp"
#include "../Commande/choix_attaquer.hpp"
#include "unite_d_elite.hpp"


const std::string Chateau::TEXTURE_FILE_NAME = "chateau.png";
const std::string Chateau::INFO = "permet de former des unites d'elite";
const std::string Chateau::NAME ="Chateau";

const std::string Chateau::ICONE_TEXTURE_FILE_NAME = "chateau_icone.png";

const std::string Chateau::SOUND_NAME_OF_SELECTION = "chateau_selection.wav";



Chateau::Chateau(Joueur_ptr joueurProprietaire) : Batiment(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Chateau::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new ChoixAttaquer(this));
    commandes->push_back(new CreerElement<unite_d_elite>(this->getCasePosition(),this->joueurProprietaire,this));
    return commandes;
}


void Chateau::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Chateau::nouveauTour() {
    resetNombreAction();
}

std::string Chateau::soundNameOfSelection() {
    return SOUND_NAME_OF_SELECTION;
}