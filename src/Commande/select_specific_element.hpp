#ifndef SELECT_SPECIFIC_ELEMENT
#define SELECT_SPECIFIC_ELEMENT

#include "commande_square.hpp"

class ElementJoueur;


/**
 * \class SelectSpecificElement
 * \brief Permet de choisir un certain element \n
 * /!\ S'ASSURER que elementPourAction passe en argument constructeur n'est pas detruit tant que
 * l'instance de SelectSpecificElement existe
*/
class SelectSpecificElement : public CommandeSquare {
    private :
        /**
         * \brief element qui sera selectionnee si l'on clique sur la commande
        */
        ElementJoueur *elementPourAction;


    public : 
        /**
         * \brief constructeur \n
         * /!\ S'ASSURER que elementPourAction passe en argument du constructeur n'est pas detruit tant que
         * l'instance de SelectSpecificElement existe
         * \param elementPourAction element qui sera selectionnee si l'on clique sur la commande
        */
        SelectSpecificElement(ElementJoueur *elementPourAction);

        void execute() override;




};









#endif