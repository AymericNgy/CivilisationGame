#include "hud.hpp"


Hud::Hud() {
    updateJoueur();
}

Hud::~Hud() {
    clearAll();
}

// ---FONCTIONS---

// RELATIF AU DASHBOARD

void Hud::removeInfoElement() {
    dashboard.removeInfoElement();
}

void Hud::removeInfoNormal() {
    dashboard.removeInfoNormal();
}



// va placer au bonne endroit et detruire les anciennes
// ne supprime pas les infos sur le dashboard
// /!\ se charge de detruire les commandes envoyées
void Hud::pushCommandeSquare(ListPtrCommandeSquare_ptr commandes) {
    dashboard.pushCommandeSquare(commandes);
}

void Hud::pushInfoElement(ElementJoueur *ElementJoueurPourInfo) {
    dashboard.pushInfoElement(ElementJoueurPourInfo);
}

// /!\ se charge de detruire les commandes envoyées ne pas reutiliser les commandes
void Hud::pushCommandes(ListPtrCommandeSquare_ptr commandes, std::string info) {
    dashboard.pushCommandes(commandes,info);
}

//detruit les comandeSquare contenu dans commandesSquare
void Hud::cleanCommandeSquare() {
    dashboard.cleanCommandeSquare();
}


void Hud::updateInfoElement() {
    dashboard.updateInfoElement();
}

bool Hud::pixelIsOn(int x, int y)const {
    // [!] A ETENDRE AVEC LES DIFFERENTS ELEMENTS
    return dashboard.pixelIsOn(x,y) || ressource.pixelIsOn(x,y) || banner.pixelIsOn(x,y);
}


void Hud::changeJoueur() {
    clearAll();
    updateJoueur();

}

// void Hud::updateRessrouces() {
//     ressource.update();
// }

void Hud::updateBanner() {
    banner.update();
}

void Hud::updateJoueur() {
    updateRessources();
    updateBanner();
}