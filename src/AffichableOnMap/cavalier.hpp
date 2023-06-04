#ifndef CAVALIER_HPP
#define CAVALIER_HPP

#include <string>
#include "batiment.hpp"
#include "unite.hpp"

#include "interface_attaquer.hpp"

/**
 * \class Cavalier
 * \brief Unite qui peut attaquer
*/
class Cavalier : public Unite , public InterfaceAttaquer {
private :

        static const int NOMBRE_ACTION_MAX_ORIGINE=3;
        static const int NOMBE_PV_MAX_ORIGINE=20;
        static constexpr float NOMBRE_CASE_DEPLACEMENT_ORIGINE=7;
        static const int NOMBRE_DEGAT_ORIGINE=20;
        static constexpr float DISTANCE_ATTAQUE_ORIGINE=2;

        static int nombreActionBonus;
        static int nombrePvBonus;
        static float mombreCaseDeplacementBonus;
        static int nombreDegatBonus;
        static float distanceAttaqueBonus;
        
        static const std::string TEXTURE_FILE_NAME;
        static const std::string INFO;
        static const std::string NAME;

        static const int COUT_ACHAT_BOIS=0;
        static const int COUT_ACHAT_NOURRITURE=35;
        static const int COUT_ACHAT_OR=15;



    protected :




    public :
        // --- CONSTANTES ----

        static const std::string ICONE_TEXTURE_FILE_NAME;

        // --- FONCTIONS ---


        void ressourcePourAchat(int &bois, int &nourriture, int &_or);



        Cavalier(Joueur_ptr joueurProprietaire);

        int getNombreActionMax() const{ return NOMBRE_ACTION_MAX_ORIGINE+nombreActionBonus;}
        
        int getPvMax() const {return NOMBE_PV_MAX_ORIGINE+nombrePvBonus;}

        // permet d'implementer InterfaceSeDeplacer
        float getNombreCaseDeplacement() const  {return NOMBRE_CASE_DEPLACEMENT_ORIGINE+mombreCaseDeplacementBonus;}
        
        // permet d'implementer InterfaceAttaquer
        float getNombreDegat() const {return NOMBRE_DEGAT_ORIGINE+nombreDegatBonus;}

        // permet d'implementer InterfaceAttaquer
        float getDistanceAttaque() const {return DISTANCE_ATTAQUE_ORIGINE+distanceAttaqueBonus;}


        ListPtrCommandeSquare_ptr getActionPossible();

        void nouveauTour();




};









#endif