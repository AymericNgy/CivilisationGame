#ifndef CONSTRUIRE
#define CONSTRUIRE

#include "commande_square.hpp"
#include "../case.hpp"


#include "creer_element.hpp"
#include "../UserInterface/UserInterface.hpp"
#include "../AffichableOnMap/element_joueur.hpp"
#include "../utile.hpp"
#include "../joueur.hpp"
#include "../jeu.hpp"


class ElementJoueur;


// [!] probleme si constructeur des classes derivees d'ElementJoueur ne sont pas les memes que ceux d'ElementJoueur
// [!] alternative : utiliser une copie d'un element passe en argument

// permet de construire un certain type d'ElementJoueur
// /!\ T doit etre un ElementJoueur ou heriter de cette classe
// /!\ S'ASSURER que elementPourAction passe en argument constructeur n'est pas detruit tant que
// /!\ l'instance de SelectSpecificElement existe 
template<typename T>
class CreerElement : public CommandeSquare {
    private :
        CasePosition position;
        Joueur_ptr joueurProprietaire;
        ElementJoueur *elementCreateur; // element qui cree l'element, permet de decrease son nombre d'action, mettre nullptr si aucun element ne cree l'element



    public : 
        CreerElement(CasePosition position,Joueur_ptr joueurProprietaire,ElementJoueur *elementPourAction);

        

        void execute();
    
};


// permet de creer un ElemenJoueur de type T (T doit etre un ElementJoueur ou heriter de cette classe)
// position -> position de creation
// joueurProprietaire -> joueur qui sera proprietaire de l'element cree
// elementCreateur -> element qui cree l'element, permet de decrease son nombre d'action, mettre nullptr si aucun element ne cree l'element
template<typename T>
CreerElement<T>::CreerElement(CasePosition position,Joueur_ptr joueurProprietaire, ElementJoueur *elementCreateur) : position(position),  joueurProprietaire(joueurProprietaire),CommandeSquare(UserInterface::TRANSPARENCY_TEXTURE_NAME, "",0,0,0) {
    
    this->elementCreateur=elementCreateur;
    
    static_assert(std::is_convertible<T*, ElementJoueur*>::value, "T doit dériver de ElementJoueur");
    
    // pas tres elegant -> utilise une instance de T pour des affectations
    T elementJoueur(joueurProprietaire);

    // initialise texture pour affichage de la commande
    this->setTextures(elementJoueur.getIconTextureFileName());

    // initialiser ressource pour l'achat de la commande
    int bois_pour_achat;
    int nourriture_pour_achat;
    int or_pour_achat;
    elementJoueur.ressourcePourAchat(bois_pour_achat,nourriture_pour_achat,or_pour_achat);

    this->prix_bois = bois_pour_achat;
    this->prix_nourriture =nourriture_pour_achat;
    this->prix_or=or_pour_achat;

    // initilaiser info
    info=elementJoueur.getName()+"\n"+elementJoueur.getInfo();


}



// execute la creation si assez de resource et assez d'action s'il y a une instance creatrice
// si il n'y a pas d'instance creatrice recharge la case selectionne dans le hud
template<typename T>
void CreerElement<T>::execute() {
    // pas tres elegant -> utilise une instance de T pour des affectations
    T instanceTypeACreer(joueurProprietaire);
    if (elementCreateur) { // teste s'il y a un element qui cree
        if (elementCreateur->_commandeCreerElement(instanceTypeACreer)) {
            ElementJoueur *nouveauElementJoueur = dynamic_cast<ElementJoueur*>(new T(joueurProprietaire));
            nouveauElementJoueur->init(false);
            nouveauElementJoueur->moveToPosition(position);


        }
    } else {
        if (ElementJoueur::_staticCommandeCreerElement(instanceTypeACreer)) {
            ElementJoueur *nouveauElementJoueur = dynamic_cast<ElementJoueur*>(new T(joueurProprietaire));
            nouveauElementJoueur->init(false);
            nouveauElementJoueur->moveToPosition(position);   

            Jeu::getInstance().getJoueurActif()->loadSelectedCase();        
        }
    }


}




















#endif