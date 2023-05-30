#include "element_joueur.hpp"
#include "../joueur.hpp"
#include "../jeu.hpp"
#include "../hud.hpp"










ElementJoueur::ElementJoueur(int couche,std::string textureFileName, std::string info,std::string name,std::string iconTextureFileName,Joueur_ptr joueurProprietaire) : AffichableOnMap(CasePosition(0,0),couche,textureFileName) {
    this->pv=0;
    this->nombreActionRestante=0;
    this->info=info;
    this->name=name;
    this->iconTextureFileName=iconTextureFileName;
    this->joueurProprietaire=joueurProprietaire;
    joueurProprietaire->_addElement(this);

    
}


ElementJoueur::~ElementJoueur() {
    std::cout << "~ElementJoueur" << std::endl;
    joueurProprietaire->_removeElement(this);
    std::cout << "fin ~ElementJoueur" << std::endl;
}

void ElementJoueur::init(bool initNombreAction) {
    pv = getPvMax();
    if (initNombreAction) {
        nombreActionRestante = getNombreActionMax();
    }
}

bool ElementJoueur::decreaseNombreAction() {
    if (nombreActionRestante>0) {
        nombreActionRestante--;
        Jeu::getInstance().getHud().updateInfoElement();
        return true;
    } else {
        return false;
    }
}

void ElementJoueur::resetNombreAction() {
    nombreActionRestante = getNombreActionMax();
}


bool ElementJoueur::_commandeCreerElement(ElementJoueur &instanceTypeACreer) {

    if (instanceTypeACreer.peutEtreAchete() && this->peutDecrementeAction()) {
        
        decreaseNombreAction();
        

        //pour decrease nourriture
        int bois_pour_achat;
        int nourriture_pour_achat;
        int or_pour_achat;
        instanceTypeACreer.ressourcePourAchat(bois_pour_achat,nourriture_pour_achat,or_pour_achat);

        Joueur_ptr joueur_actif = Jeu::getInstance().getJoueurActif();
        joueur_actif->decreaseBois(bois_pour_achat);
        joueur_actif->decreaseNourriture(nourriture_pour_achat);
        joueur_actif->decreaseOr(or_pour_achat);
        return true;
    }
    return false;
}

bool ElementJoueur::_staticCommandeCreerElement(ElementJoueur &instanceTypeACreer) {
    if (instanceTypeACreer.peutEtreAchete() ) {

        //pour decrease nourriture
        int bois_pour_achat;
        int nourriture_pour_achat;
        int or_pour_achat;
        instanceTypeACreer.ressourcePourAchat(bois_pour_achat,nourriture_pour_achat,or_pour_achat);

        Joueur_ptr joueur_actif = Jeu::getInstance().getJoueurActif();
        joueur_actif->decreaseBois(bois_pour_achat);
        joueur_actif->decreaseNourriture(nourriture_pour_achat);
        joueur_actif->decreaseOr(or_pour_achat);
        return true;
    }
    return false;
}


bool ElementJoueur::peutEtreAchete(){
    Joueur_ptr joueur_actif = Jeu::getInstance().getJoueurActif();
    int bois = joueur_actif->getBois();
    int nourriture = joueur_actif->getNourriture();
    int _or =joueur_actif->getOr();


    int bois_pour_achat;
    int nourriture_pour_achat;
    int or_pour_achat;

    // [!] pas elegant mais permet de simuler une methode statique abstraite
    this->ressourcePourAchat(bois_pour_achat,nourriture_pour_achat,or_pour_achat);

    
    return (bois-bois_pour_achat)>0 && (nourriture-nourriture_pour_achat)>0 && (_or-or_pour_achat)>0;


}

bool ElementJoueur::decreasePv(int pv) {
    this->pv-=pv;
    if (this->pv<=0) {

        delete this;

        return true;
    }
    return false;
}

std::string ElementJoueur::soundNameOfSelection() {
    return "";
}

std::string ElementJoueur::soundNameOfDestruction() {
    return "";
}