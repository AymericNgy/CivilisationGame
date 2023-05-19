#ifndef SE_DEPLACER
#define SE_DEPLACER

#include "commande_square.hpp"



class InterfaceSeDeplacer;


// permet de deplacer une instance de InterfaceSeDeplacer
// /!\ S'ASSURER que elementPourAction passe en argument constructeur n'est pas detruit tant que
// /!\ l'instance de InterfaceSeDeplacer existe 
class SeDeplacer : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO ;
        InterfaceSeDeplacer *elementPourAction;
    
    public :
        SeDeplacer(InterfaceSeDeplacer *elementPourAction);
        void execute();
};















#endif