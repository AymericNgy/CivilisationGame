#ifndef CHOIX_CONSTRUIRE
#define CHOIX_CONSTRUIRE

#include "commande_square.hpp"

class Case ;
typedef std::shared_ptr<Case> Case_ptr;

/**
 * \class ChoixConstruire
 * \brief permet de choisir de construire sur une case
*/
class ChoixConstuire : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;
        Case_ptr casePourAction;


    public : 
        /**
         * \brief constructeur
         * \param casePourAction case sur laquelle on veut construire
        */
        ChoixConstuire(Case_ptr casePourAction);
        void execute();




};









#endif