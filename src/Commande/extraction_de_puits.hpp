#ifndef EXTRACTION_DE_PUITS_HPP
#define EXTRACTION_DE_PUITS_HPP

#include "commande_square.hpp"

class Mine;


/**
 * \class ExtractionDePuits
 * \brief permet d'evoluer au niveau 2 de production d'or la mine
*/
class ExtractionDePuits : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;

        Mine *minePourAction;

        static const int PRIX_OR = 500;
    
    public :
        /**
         * \brief constructeur
         * \param minePourAction mine qu'on veut faire evoluer
        */
        ExtractionDePuits(Mine *minePourAction);
        void execute();


};




#endif