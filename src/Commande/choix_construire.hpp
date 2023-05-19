#ifndef CHOIX_CONSTRUIRE
#define CHOIX_CONSTRUIRE

#include "commande_square.hpp"

class Case ;
typedef std::shared_ptr<Case> Case_ptr;


class ChoixConstuire : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;
        Case_ptr casePourAction;


    public : 
        ChoixConstuire(Case_ptr casePourAction);
        void execute();




};









#endif