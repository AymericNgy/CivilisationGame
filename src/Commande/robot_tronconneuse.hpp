#ifndef ROBOT_TRONCONNEUSE
#define ROBOT_TRONCONNEUSE

#include "commande_square.hpp"

class Camp_de_bucheron;

// permet d'evoluer au niveau 2 de production d'or la mine
class RobotTronconneuse : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;

        Camp_de_bucheron *campPourAction;

        static const int PRIX_OR = 1500;
    
    public :
        RobotTronconneuse (Camp_de_bucheron* campPourAction);
        void execute();


};




#endif