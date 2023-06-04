#ifndef MINE_HPP
#define MINE_HPP

#include <string>
#include "batiment.hpp"
#include "interface_cree_ressource.hpp"

/**
 * \class Mine
 * \brief Mine est un Batiment qui permet de produire de l'or
*/
class Mine : public Batiment , public InterfaceCreeRessource {
    private :
        static const int NOMBRE_ACTION_MAX_ORIGINE=1;

        static const int NOMBE_PV_MAX_ORIGINE=100;


        static int nombreActionBonus;
        static int nombrePvBonus;
 
        static int productionOr;

        static bool extractionDePuitsDebloque;
        static bool robotMineurDebloque;

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

        static const int PRODUCTION_OR_ORIGINE = 20;
        static const int PRODUCTION_OR_EXCTRACTION_DE_PUITS = 40; 
        static const int PRODUCTION_OR_ROBOT_MINEUR = 80;


        // --- METHODES ---

        Mine(Joueur_ptr joueurProprietaire);

        int getNombreActionMax() const{ return NOMBRE_ACTION_MAX_ORIGINE+nombreActionBonus;}
        
        int getPvMax() const {return NOMBE_PV_MAX_ORIGINE+nombrePvBonus;}

        ListPtrCommandeSquare_ptr getActionPossible();

        void nouveauTour();


        void ressourcePourAchat(int &bois, int &nourriture, int &_or);

        // permet d'implementer InterfaceCreeRessource
        void ressourceParTour(int &bois, int &nourriture, int &_or);

        // modifie la production de la mine
        static void _commandeExtractionDePuits();

        // modifie la production de la mine 
        static void _commandeRobotMineur();

        bool getExtractionDePuitsDebloque() {return extractionDePuitsDebloque;}

        bool getRobotMineurDebloque() {return robotMineurDebloque;}

        std::string soundNameOfSelection() override;



};








#endif