#ifndef ROBOT_MINEUR_HPP
#define ROBOT_MINEUR_HPP

#include "commande_square.hpp"

class Mine;



/**
 * \class RobotMineur
 * \brief niveau 3 de production d'or de la Mine
 * 
*/
class RobotMineur : public CommandeSquare {
    private :
        static const std::string TEXTURE_NAME;
        static const std::string INFO;

        Mine *minePourAction;

        static const int PRIX_OR = 1500;
    
    public :

        /**
         * \brief constructeur
         * 
        */
        RobotMineur(Mine *minePourAction);
        void execute();


};




#endif