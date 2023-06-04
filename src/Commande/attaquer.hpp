#ifndef ATTAQUER_HPP
#define ATTAQUER_HPP

#include "commande_square.hpp"

class InterfaceAttaquer;


/**
 * \class Attaquer
 * permet de faire attaquer une instance de InterfaceAttaquer \n
 * /!\ S'ASSURER que elementPourAction passe en argument constructeur n'est pas detruit tant que
 * l'instance de ChoixSeDeplacer existe
*/
class Attaquer : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO ;
        InterfaceAttaquer *elementPourAction;
    
    public :
        Attaquer(InterfaceAttaquer *elementPourAction);
        void execute();
};













#endif
