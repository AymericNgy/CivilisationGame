#ifndef ROBOT_FAUCHEUR
#define ROBOT_FAUCHEUR

#include "commande_square.hpp"

class Moulin;



/**
 * \class RobotFaucheur
 * permet d'evoluer au niveau 3 de produtuction de nourriture du Moulin
 */
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