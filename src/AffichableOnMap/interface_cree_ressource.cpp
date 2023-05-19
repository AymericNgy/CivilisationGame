#include "interface_cree_ressource.hpp"
#include "../utile.hpp"
#include "element_joueur.hpp"
#include "../jeu.hpp"
#include "../joueur.hpp"



ElementJoueur *InterfaceCreeRessource::thisElementJoueur() {
    ElementJoueur *ele = dynamic_cast<ElementJoueur*>(this);
    if (ele) {
        return ele;
    } else {
        Utile::erreur("InterfaceCreeRessource::thisElementJoueur()","InterfaceCreeRessource doit etre implemente sur un ElementJoueur");
    }
}


void InterfaceCreeRessource::creationRessource() {
    int bois=0;
    int nourriture=0;
    int _or=0;
    ressourceParTour(bois,nourriture,_or);
    Jeu::getInstance().getJoueurActif()->increaseRessource(bois, nourriture, _or);
    

}