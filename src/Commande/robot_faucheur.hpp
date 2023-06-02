#ifndef ROBOT_FAUCHEUR
#define ROBOT_FAUCHEUR

#include "commande_square.hpp"

class Moulin;

// permet d'evoluer au niveau 2 de production d'or la mine
class RobotFaucheur : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;

        Moulin *moulinPourAction;

        static const int PRIX_OR = 1500;
    
    public :
        RobotFaucheur (Moulin* moulinPourAction);
        void execute();


};




#endif