#ifndef MOULIN
#define MOULIN

#include <string>
#include "batiment.hpp"
#include "interface_cree_ressource.hpp"


/**
 * \class Moulin
 * \brief batiment qui permet de produire de la nourriture
*/
class Moulin : public Batiment , public InterfaceCreeRessource {
    private :
        static const int NOMBRE_ACTION_MAX_ORIGINE=1;

        static const int NOMBE_PV_MAX_ORIGINE=150;


        static int nombreActionBonus;
        static int nombrePvBonus;
 
        static int productionNourriture;

        static bool fauxTranchanteDebloque;
        static bool robotFaucheurDebloque;

        static const std::string TEXTURE_FILE_NAME;
        static const std::string INFO;
        static const std::string NAME;

        static const std::string SOUND_NAME_OF_SELECTION;





        static const int COUT_ACHAT_BOIS=100;
        static const int COUT_ACHAT_NOURRITURE=0;
        static const int COUT_ACHAT_OR=0;


public :
        // --- CONSTANTES ---

        static const std::string ICONE_TEXTURE_FILE_NAME;

        static const int PRODUCTION_NOURRITURE_ORIGINE = 20;
        static const int PRODUCTION_NOURRITURE_FAUX_TRANCHANTE = 40; 
        static const int PRODUCTION_NOURRITURE_ROBOT_FAUCHEUR = 80;


        // --- METHODES ---
        
        Moulin(Joueur_ptr joueurProprietaire);
        
        int getNombreActionMax() const{ return NOMBRE_ACTION_MAX_ORIGINE+nombreActionBonus;}
        
        int getPvMax() const {return NOMBE_PV_MAX_ORIGINE+nombrePvBonus;}

        ListPtrCommandeSquare_ptr getActionPossible();

        void nouveauTour();


        void ressourcePourAchat(int &bois, int &nourriture, int &_or);

        // permet d'implementer InterfaceCreeRessource
        void ressourceParTour(int &bois, int &nourriture, int &_or);

        // modifie la production du camp_de_bucheron
        static void _commandeFauxTranchante();

        // modifie la production du camp_de_bucheron 
        static void _commandeRobotFaucheur();

        bool getFauxTranchanteDebloque() {return fauxTranchanteDebloque;}

        bool getRobotFaucheurDebloque() {return robotFaucheurDebloque;}

        std::string soundNameOfSelection() override;



};


#endif

