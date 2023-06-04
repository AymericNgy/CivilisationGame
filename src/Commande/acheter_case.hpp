#ifndef ACHETER_CASE
#define ACHETER_CASE

#include "commande_square.hpp"

class Case ;
typedef std::shared_ptr<Case> Case_ptr;

/**
 * \class AcheterCase
 * \brief permet d'acheter une case
*/
class AcheterCase : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;
        Case_ptr casePourAction;

        static const int COUT_ACHAT_BOIS=0;
        static const int COUT_ACHAT_NOURRITURE=0;
        static const int COUT_ACHAT_OR=50;

    public : 
        /**
         * \brief constructeur
         * \param casePourAction case qu'on veut acheter
        */
        AcheterCase(Case_ptr casePourAction);
        void execute();




};























#endif