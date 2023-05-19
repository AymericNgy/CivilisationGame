#ifndef CHOIX_ATTAQUER
#define CHOIX_ATTAQUER

#include "commande_square.hpp"

class InterfaceAttaquer;

// permet de choisir de faire attaquer une instance de ChoixAttaquer
// /!\ S'ASSURER que elementPourAction passe en argument constructeur n'est pas detruit tant que
// /!\ l'instance de ChoixSeDeplacer existe 
class ChoixAttaquer : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;
        InterfaceAttaquer *elementPourAction;

    public :
        ChoixAttaquer(InterfaceAttaquer *elementPourAction);
        void execute();

};















#endif