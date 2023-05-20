#ifndef MINE_HPP
#define MINE_HPP

#include <string>
#include "batiment.hpp"
#include "interface_cree_ressource.hpp"

class Mine : public Batiment , public InterfaceCreeRessource {
    private :
        static const int NOMBRE_ACTION_MAX_ORIGINE=1;

        static const int NOMBE_PV_MAX_ORIGINE=100;

        static const int BOIS_PAR_TOUR_ORIGINE = 0;
        static const int NOURRITURE_PAR_TOUR_ORIGINE = 0;       
        static const int OR_PAR_TOUR_ORIGINE = 20;

        static int nombreActionBonus;
        static int nombrePvBonus;

        static int boisParTourBonus;
        static int nourritureParTourBonus;       
        static int orParTourBonus;

        static const std::string TEXTURE_FILE_NAME;
        static const std::string INFO;
        static const std::string NAME;

        

        // /!\ ne peut pas etre achete
        static const int COUT_ACHAT_BOIS=100;
        static const int COUT_ACHAT_NOURRITURE=0;
        static const int COUT_ACHAT_OR=0;


public :
        static const std::string ICONE_TEXTURE_FILE_NAME;

        Mine(Joueur_ptr joueurProprietaire);

        int getNombreActionMax() const{ return NOMBRE_ACTION_MAX_ORIGINE+nombreActionBonus;}
        
        int getPvMax() const {return NOMBE_PV_MAX_ORIGINE+nombrePvBonus;}

        ListPtrCommandeSquare_ptr getActionPossible();

        void nouveauTour();


        void ressourcePourAchat(int &bois, int &nourriture, int &_or);

        // permet d'implementer InterfaceCreeRessource
        void ressourceParTour(int &bois, int &nourriture, int &_or);




};








#endif