#ifndef LANCER_PARTIE_HPP
#define LANCER_PARTIE_HPP

#include "commande.hpp"


/**
 * \class LancerPartie
 * \brief permet de lancer la partie
*/
class LancerPartie : public Commande {
    private:
        static const int WIDTH = 220;
        static const int HEIGHT  =152;

        static const int POSITION_X = 100;
        static const int POSITION_Y = 100;

        static const int COUCHE = 1;

        static const std::string TEXTURE_NAME;
        static const std::string INFO;

    public:
        LancerPartie();

        void execute();
};







#endif