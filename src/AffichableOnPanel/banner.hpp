#ifndef BANNER
#define BANNER

#include "../UserInterface/affichable_on_panel.hpp"



/**
 * \class Banner
 * \brief prend la couleur du joueur actif quand Banner::update() est appele
*/
class Banner : public AffichableOnPanel {
    private :
        static const int COUCHE = 20;
        
        static const int WIDTH = 100;
        static const int HEIGHT = 100;

        static const int POSITION_X; 
        static const int POSITION_Y;

        static const std::string TEXTURE_NAME;

    public :

        Banner();

        /**
         * \brief met a jour la couleur du joueur actif
        */
        void update();





};



















#endif