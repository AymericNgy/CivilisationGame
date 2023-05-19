#ifndef COMMANDE_CONSTRUCT_CASERNE
#define COMMANDE_CONSTRUCT_CASERNE
 

#include "commande_square.hpp"

// [!] A changer pour etre plus generique -> CommandeConstructElement
class CommandeConstructCaserne : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;

    public : 
        CommandeConstructCaserne();
        void execute();

};


#endif
