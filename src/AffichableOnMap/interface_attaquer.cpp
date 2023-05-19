#include "interface_attaquer.hpp"
#include "element_joueur.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"
#include "../hud.hpp"
#include "../Commande/attaquer.hpp"
#include "../UserInterface/UserInterface.hpp"


#include "../utile.hpp"

ElementJoueur *InterfaceAttaquer::thisElementJoueur() {
    ElementJoueur *ele = dynamic_cast<ElementJoueur*>(this);
    if (ele) {
        return ele;
    } else {
        Utile::erreur("InterfaceAttaquer::thisElementJoueur()","InterfaceAttaquer doit etre implemente sur un ElementJoueur");
    }
}



void InterfaceAttaquer::_commandeAttaquer() {
    CasePosition selectedCasePosition =  UserInterface::getInstance().getSelectedCase();
    Joueur_ptr joueurActif = Jeu::getInstance().getJoueurActif();
    ElementJoueur *ennemiPourAttaque = Jeu::getInstance().getPlateau().ennemiSurCase(joueurActif,selectedCasePosition);
    if (ennemiPourAttaque && thisElementJoueur()->decreaseNombreAction()) {
        // [!] rajouter coeff multiplicatif
        ennemiPourAttaque->decreasePv(this->getNombreDegat());
        Jeu::getInstance().getJoueurActif()->changeEtatSelectedCase(Joueur::NORMAL);
        UserInterface::getInstance().clearCircle();

        Jeu::getInstance().getHud().pushInfoElement(thisElementJoueur());
    }
}

void InterfaceAttaquer::_commandeChoixAttaquer() {
    if (thisElementJoueur()->getNombreActionRestante()>0) {
        UserInterface &ui = UserInterface::getInstance();
        ui.drawCircle(getDistanceAttaque(),thisElementJoueur()->getCasePosition());

        Jeu::getInstance().getJoueurActif()->changeEtatSelectedCase(Joueur::ATTAQUER);
        ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
        commandes->push_back(new Attaquer(this));
        Jeu::getInstance().getHud().pushCommandeSquare(commandes);
    }
}