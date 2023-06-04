#ifndef RESSOURCE
#define RESSOURCE

#include "../UserInterface/affichable_on_panel.hpp"


class TextForUI;



/**
 * \class Ressource
 * \brief permet d'afficher les ressources du joueur actif
*/
class Ressource : public AffichableOnPanel{
    private :
        // ---CONSTANTES---

        static const int COUCHE = 20;

        static const std::string TEXTURE_NAME;

        // ---TAILLES SUR IMAGE---

        static const int POSITION_X = 0; //pxl
        static const int POSITION_Y = 0; //pxl

        static const int POSITION_BOIS_X = POSITION_X + 64; //pxl
        static const int POSITION_BOIS_Y = POSITION_Y + 25; //pxl
        static const int POSITION_NOURRITURE_X = POSITION_X + 179; //pxl
        static const int POSITION_NOURRITURE_Y = POSITION_Y + 25; //pxl
        static const int POSITION_OR_X = POSITION_X + 295; //pxl
        static const int POSITION_OR_Y = POSITION_Y + 25; //pxl



        static const int CHARACTER_SIZE = 19;

        // ---ATTRIBUTS---

        // RESSOURCES mettre a jour par rapport au joueurActif avec Ressource::update()
        int _bois;
        int _nourriture;
        int _or;

        TextForUI *text_bois;
        TextForUI *text_nourriture;
        TextForUI *text_or;


        // ---FONCTIONS---
        



        /**
         * \brief /!\ a ne faire que dans le constructeur
        */
        void initInfo();



    public :

        Ressource();
        ~Ressource();


        /**
         * \brief Met a jour toutes les ressouces avec celles du joueur actif
        */
        void update();



};






#endif