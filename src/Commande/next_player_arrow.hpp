#ifndef NEXT_PLAYER
#define NEXT_PLAYER

#include "commande.hpp"




// METTRE DANS COMMANDE..
class NextPlayerArrow : public Commande {
    private:
        static const int WIDTH = 220;
        static const int HEIGHT  =152;

        static const int POSITION_X;
        static const int POSITION_Y;

        static const int COUCHE = 20;

        static const std::string TEXTURE_NAME;
        static const std::string INFO;

    public:
        NextPlayerArrow();

        void execute();





};













#endif