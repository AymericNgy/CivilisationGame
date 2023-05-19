#ifndef SELECT_ELEMENT
#define SELECT_ELEMENT

#include "commande_square.hpp"

class Case ;
typedef std::shared_ptr<Case> Case_ptr;

// permet de choisir l'option de choisir un element specifique sur une case
class SelectElement : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO ;
        Case_ptr casePourAction;


    public : 
        SelectElement(Case_ptr casePourAction);
        void execute();




};









#endif