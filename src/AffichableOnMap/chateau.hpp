#ifndef CHATEAU
#define CHATEAU

#include <string>
#include "batiment.hpp"
#include "interface_attaquer.hpp"



/**
 * \class Chateau
 * \brief Batiment qui peut attaquer
 * et construire l'unite d'elite
*/
class Chateau : public Batiment , public InterfaceAttaquer{
    private :
        static const int NOMBRE_ACTION_MAX_ORIGINE=2;
        static const int NOMBE_PV_MAX_ORIGINE=300;

        static int nombreActionBonus;
        static int nombrePvBonus;
        
        static const std::string TEXTURE_FILE_NAME;
        static const std::string INFO;
        static const std::string NAME;

        static const int COUT_ACHAT_BOIS=4000;
        static const int COUT_ACHAT_NOURRITURE=0;
        static const int COUT_ACHAT_OR=200;

        static const int NOMBRE_DEGAT_ORIGINE=40;
        static constexpr float DISTANCE_ATTAQUE_ORIGINE=5;

        static const std::string SOUND_NAME_OF_SELECTION;
        


    protected :


    public :
        static const std::string ICONE_TEXTURE_FILE_NAME;

        Chateau(Joueur_ptr joueurProprietaire);

        int getNombreActionMax() const{ return NOMBRE_ACTION_MAX_ORIGINE;}
        
        int getPvMax() const {return NOMBE_PV_MAX_ORIGINE;}

        ListPtrCommandeSquare_ptr getActionPossible();

        void nouveauTour();


        void ressourcePourAchat(int &bois, int &nourriture, int &_or);

         // permet d'implementer InterfaceAttaquer
        float getNombreDegat() const {return NOMBRE_DEGAT_ORIGINE;}

        // permet d'implementer InterfaceAttaquer
        float getDistanceAttaque() const {return DISTANCE_ATTAQUE_ORIGINE;}

        std::string soundNameOfSelection() override;

        




};




#endif