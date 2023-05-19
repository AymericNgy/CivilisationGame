#ifndef SELECT_SPECIFIC_ELEMENT
#define SELECT_SPECIFIC_ELEMENT

#include "commande_square.hpp"

class ElementJoueur;

// permet de choisir un certain element
// /!\ S'ASSURER que elementPourAction passe en argument constructeur n'est pas detruit tant que
// /!\ l'instance de SelectSpecificElement existe 
class SelectSpecificElement : public CommandeSquare {
    private :
        ElementJoueur *elementPourAction;


    public : 
        SelectSpecificElement(ElementJoueur *elementPourAction);
        void execute();




};









#endif