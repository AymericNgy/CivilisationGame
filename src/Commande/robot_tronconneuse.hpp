#ifndef ROBOT_TRONCONNEUSE
#define ROBOT_TRONCONNEUSE

#include "commande_square.hpp"

class Camp_de_bucheron;


/**
 * \class RobotTronconneuse
 * \brief Permet d'evoluer au niveau 2 de production de bois du camp de bucheron
*/
class RobotTronconneuse : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;

        /**
         * \brief camp de bucheron qu'on veut faire evoluer
        */
        Camp_de_bucheron *campPourAction;

        /**
         * \brief prix en or de l'evolution
        */
        static const int PRIX_OR = 1500;
    
    public :

        /**
         * \brief constructeur
         * \param campPourAction camp de bucheron qu'on veut faire evoluer
        */
        RobotTronconneuse (Camp_de_bucheron* campPourAction);
        
        void execute() override;


};




#endif