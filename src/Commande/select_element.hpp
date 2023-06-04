#ifndef SELECT_ELEMENT
#define SELECT_ELEMENT

#include "commande_square.hpp"

class Case ;
typedef std::shared_ptr<Case> Case_ptr;



/**
 * \class SelectElement
 * \brief Permet de l'option de choisir un element specifique sur une case
*/
class SelectElement : public CommandeSquare {
    private :
        /**
         * \brief nom de la texture de la commande
        */
        static const std::string TEXTURE_NAME;

        /**
         * \brief info relative a la commande
        */
        static const std::string INFO ;

        /**
         * \brief case sur laquelle on veut selectionner un element
        */
        Case_ptr casePourAction;


    public : 
        /**
         * \brief constructeur
         * \param casePourAction case sur laquelle on veut selectionner un element
        */
        SelectElement(Case_ptr casePourAction);
        
        void execute() override;




};









#endif