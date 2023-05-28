#ifndef MENU_HPP
#define MENU_HPP

#include "../UserInterface/affichable_on_panel.hpp"
#include "../Commande/lancer_partie.hpp"

class Menu : public AffichableOnPanel {
    private :
    // ---CONSTANTES---

        // ---TAILLES SUR IMAGE---
        static const int WIDTH = 1920; // en pxl
        static const int HEIGHT = 1040; //en pxl

        static const int POSITION_X = 0; // en pxl
        static const int POSITION_Y = 0;// en pxl  

        static const int COUCHE = 0;

        static const std::string TEXTURE_NAME;

        LancerPartie lancerPartieBouton;



    public :
        Menu();


};





















#endif