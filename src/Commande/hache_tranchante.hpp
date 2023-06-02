#ifndef HACHE_TRANCHANTE_HPP
#define HACHE_TRANCHANTE_HPP

#include "commande_square.hpp"

class Camp_de_bucheron;

// permet d'evoluer au niveau 2 de production d'or la mine
class HacheTranchante : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;

        Camp_de_bucheron *campPourAction;

        static const int PRIX_OR = 500;
    
    public :
        HacheTranchante(Camp_de_bucheron*campPourAction);
        void execute();


};




#endif