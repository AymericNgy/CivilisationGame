#include "caserne.hpp"
#include "../Commande/creer_element.hpp"
#include "fantassin.hpp"
#include "mage.hpp"
#include "cavalier.hpp"
#include "archer.hpp"
#include "engin_de_siege.hpp"
#include "unite_d_elite.hpp"


const std::string Caserne::TEXTURE_FILE_NAME = "caserne_mini.png";
const std::string Caserne::INFO = "permet de former de l'infanterie";
const std::string Caserne::NAME ="Caserne";

const std::string Caserne::ICONE_TEXTURE_FILE_NAME = "caserne_icone.png";

const std::string Caserne::SOUND_NAME_OF_SELECTION = "caserne_selection.wav";


int Caserne::nombreActionBonus = 0;
int Caserne::nombrePvBonus = 0;




Caserne::Caserne(Joueur_ptr joueurProprietaire) : Batiment(TEXTURE_FILE_NAME,INFO,NAME,ICONE_TEXTURE_FILE_NAME,joueurProprietaire) {


}

ListPtrCommandeSquare_ptr Caserne::getActionPossible(){
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new CreerElement<Fantassin>(this->getCasePosition(),this->joueurProprietaire,this));
    commandes->push_back(new CreerElement<Cavalier>(this->getCasePosition(),this->joueurProprietaire,this));
    commandes->push_back(new CreerElement<Mage>(this->getCasePosition(),this->joueurProprietaire,this));
    commandes->push_back(new CreerElement<Archer>(this->getCasePosition(),this->joueurProprietaire,this));
    commandes->push_back(new CreerElement<EnginDeSiege>(this->getCasePosition(),this->joueurProprietaire,this));
    commandes->push_back(new CreerElement<unite_d_elite>(this->getCasePosition(),this->joueurProprietaire,this));




    return commandes;
}


void Caserne::ressourcePourAchat(int &bois, int &nourriture, int &_or) {
    bois = COUT_ACHAT_BOIS;
    nourriture = COUT_ACHAT_NOURRITURE;
    _or = COUT_ACHAT_OR;
}

void Caserne::nouveauTour() {
    resetNombreAction();
}

std::string Caserne::soundNameOfSelection() {
    return SOUND_NAME_OF_SELECTION;
}