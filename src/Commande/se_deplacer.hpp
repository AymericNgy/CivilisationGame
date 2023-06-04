#ifndef SE_DEPLACER
#define SE_DEPLACER

#include "commande_square.hpp"



class InterfaceSeDeplacer;




/**
 * \class SeDeplacer
 * \brief Permet de deplacer une instance de InterfaceSeDeplacer \n
 * /!\ S'ASSURER que elementPourAction passe en argument du constructeur n'est pas detruit tant que l'instance de InterfaceSeDeplacer existe
*/
class SeDeplacer : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO ;
        /**
         * \brief element qui sera deplace si l'on clique sur la commande
        */
        InterfaceSeDeplacer *elementPourAction;
    
    public :

        /**
         * \brief constructeur \n
         * /!\ S'ASSURER que elementPourAction passe en argument du constructeur n'est pas detruit tant que l'instance de InterfaceSeDeplacer existe
         * \param elementPourAction element qui sera deplace si l'on clique sur la commande
        */
        SeDeplacer(InterfaceSeDeplacer *elementPourAction);

        void execute() override;
};















#endif