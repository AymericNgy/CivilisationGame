#ifndef HOTEL_DE_VILLE_HPP
#define HOTEL_DE_VILLE_HPP

#include <string>
#include "batiment.hpp"
#include "interface_cree_ressource.hpp"
#include "interface_attaquer.hpp"


// premier batiment du joueur
// lorsqu'il est detruit le joueur perd

/**
 * \class HotelDeVille
 * \brief premier batiment du joueur \n
 * lorsqu'il est detruit le joueur perd
*/
class HotelDeVille : public Batiment , public InterfaceCreeRessource , public InterfaceAttaquer{
    private :
        static const int NOMBRE_ACTION_MAX_ORIGINE=3;

        static const int NOMBE_PV_MAX_ORIGINE=500;

        static const int BOIS_PAR_TOUR_ORIGINE = 50;
        static const int NOURRITURE_PAR_TOUR_ORIGINE = 50;       
        static const int OR_PAR_TOUR_ORIGINE = 20;

        static const int NOMBRE_DEGAT_ORIGINE=20;
        static constexpr float DISTANCE_ATTAQUE_ORIGINE=3;


        static int nombreActionBonus;
        static int nombrePvBonus;

        static int boisParTourBonus;
        static int nourritureParTourBonus;       
        static int orParTourBonus;

        static int nombreDegatBonus;
        static float distanceAttaqueBonus;
        
        static const std::string TEXTURE_FILE_NAME;
        static const std::string INFO;
        static const std::string NAME;

        static const std::string SOUND_NAME_OF_SELECTION;


        // /!\ ne peut pas etre achete
        static const int COUT_ACHAT_BOIS=0;
        static const int COUT_ACHAT_NOURRITURE=0;
        static const int COUT_ACHAT_OR=0;

    protected :


    public :
        static const std::string ICONE_TEXTURE_FILE_NAME;

        HotelDeVille(Joueur_ptr joueurProprietaire);


        int getNombreActionMax() const{ return NOMBRE_ACTION_MAX_ORIGINE+nombreActionBonus;}
        
        int getPvMax() const {return NOMBE_PV_MAX_ORIGINE+nombrePvBonus;}

        ListPtrCommandeSquare_ptr getActionPossible();

        void nouveauTour();


        void ressourcePourAchat(int &bois, int &nourriture, int &_or);

        // permet d'implementer InterfaceCreeRessource
        void ressourceParTour(int &bois, int &nourriture, int &_or);

        // permet d'implementer InterfaceAttaquer
        float getNombreDegat() const {return NOMBRE_DEGAT_ORIGINE+nombreDegatBonus;}

        // permet d'implementer InterfaceAttaquer
        float getDistanceAttaque() const {return DISTANCE_ATTAQUE_ORIGINE+distanceAttaqueBonus;}

        std::string soundNameOfSelection() override;

};






#endif 