#ifndef FAUX_TRANCHANTE_HPP
#define FAUX_TRANCHANTE_HPP

#include "commande_square.hpp"

class Moulin;


/**
 * \class FauxTranchante
 * \brief permet d'evoluer au niveau 2 de production de nourriture du Moulin
 */
class FauxTranchante : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;

        Moulin *moulinPourAction;

        static const int PRIX_OR = 500;
    
    public :
        /**
         * \brief constructeur
         * \param moulinPourAction moulin qu'on veut faire evoluer
        */
        FauxTranchante(Moulin *moulinPourAction);
        void execute();


};




#endif