#ifndef CASERNE
#define CASERNE

#include <string>
#include "batiment.hpp"



class Caserne : public Batiment{
    private :
        static const int NOMBRE_ACTION_MAX_ORIGINE=2;
        static const int NOMBE_PV_MAX_ORIGINE=150;

        static int nombreActionBonus;
        static int nombrePvBonus;
        
        static const std::string TEXTURE_FILE_NAME;
        static const std::string INFO;
        static const std::string NAME;

        static const int COUT_ACHAT_BOIS=150;
        static const int COUT_ACHAT_NOURRITURE=0;
        static const int COUT_ACHAT_OR=0;
        


    protected :


    public :
        static const std::string ICONE_TEXTURE_FILE_NAME;

        Caserne(Joueur_ptr joueurProprietaire);

        int getNombreActionMax() const{ return NOMBRE_ACTION_MAX_ORIGINE+nombreActionBonus;}
        
        int getPvMax() const {return NOMBE_PV_MAX_ORIGINE+nombrePvBonus;}

        ListPtrCommandeSquare_ptr getActionPossible();

        void nouveauTour();


        void ressourcePourAchat(int &bois, int &nourriture, int &_or);




};




#endif