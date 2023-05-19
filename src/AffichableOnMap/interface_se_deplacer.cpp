
#include "interface_se_deplacer.hpp"
#include "../case.hpp"
#include "../UserInterface/UserInterface.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"
#include "../hud.hpp"
#include "../Commande/se_deplacer.hpp"
#include "../Commande/choix_se_deplacer.hpp"
#include "../utile.hpp"

void InterfaceSeDeplacer::_commandeSeDeplacer() {
    
    
    float distance_parcouru = Plateau::distance(UserInterface::getInstance().getSelectedCase(),thisElementJoueur()->getCasePosition()); 


    if ((distance_parcouru > 0.01) && (distance_parcouru <= getNombreCaseDeplacement())&& thisElementJoueur()->decreaseNombreAction()) {
        thisElementJoueur()->moveToPosition(UserInterface::getInstance().getSelectedCase());
        Jeu::getInstance().getJoueurActif()->changeEtatSelectedCase(Joueur::NORMAL);
        UserInterface::getInstance().clearCircle();

        Jeu::getInstance().getHud().pushInfoElement(thisElementJoueur());
    }
}


void InterfaceSeDeplacer::_commandeChoixSeDeplacer() {
    if (thisElementJoueur()->getNombreActionRestante()>0) {
        UserInterface &ui = UserInterface::getInstance();
        ui.drawCircle(getNombreCaseDeplacement(),thisElementJoueur()->getCasePosition());
        Jeu::getInstance().getJoueurActif()->changeEtatSelectedCase(Joueur::DEPLACER_UNITE);

        ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
        commandes->push_back(new SeDeplacer(this));
        Jeu::getInstance().getHud().pushCommandeSquare(commandes);
    }
}

ElementJoueur *InterfaceSeDeplacer::thisElementJoueur() {
    ElementJoueur *ele = dynamic_cast<ElementJoueur*>(this);
    if (ele) {
        return ele;
    } else {
        Utile::erreur("InterfaceSeDeplacer::thisElementJoueur()","InterfaceSeDeplacer doit etre implemente sur un ElementJoueur");
    }
}


























