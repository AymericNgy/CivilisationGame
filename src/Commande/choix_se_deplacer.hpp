#ifndef CHOIX_SE_DEPLACER
#define CHOIX_SE_DEPLACER

#include "commande_square.hpp"



class InterfaceSeDeplacer;



/**
 * \class ChoixSeDeplacer
 * \brief permet de choisir de deplacer une instance de InterfaceSeDeplacer
 * /!\ S'ASSURER que elementPourAction passe en argument constructeur n'est pas detruit tant que l'instance de ChoixSeDeplacer existe
*/
class ChoixSeDeplacer : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;
        InterfaceSeDeplacer *elementPourAction;
    
    public :
        ChoixSeDeplacer(InterfaceSeDeplacer *elementPourAction);
        void execute();

};















#endif