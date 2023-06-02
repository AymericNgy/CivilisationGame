#ifndef FAUX_TRANCHANTE_HPP
#define FAUX_TRANCHANTE_HPP

#include "commande_square.hpp"

class Moulin;

// permet d'evoluer au niveau 2 de production d'or la mine
class FauxTranchante : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;

        Moulin *moulinPourAction;

        static const int PRIX_OR = 500;
    
    public :
        FauxTranchante(Moulin *moulinPourAction);
        void execute();


};




#endif