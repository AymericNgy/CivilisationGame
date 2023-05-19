
#include "../UserInterface/affichable_on_map.hpp"
#include <string>
#include "terrain.hpp"

typedef std::shared_ptr<Joueur> Joueur_ptr;


class Marque : public AffichableOnMap {



    public :



        enum TYPE_MARQUE{OVER,SELECT,CIRCLE};
    
        Marque(TYPE_MARQUE typeMarque,Plateau &plateau);
        
        // Cree une marque de la couleur du propriétaire
        Marque(Joueur_ptr joueurProprietaire,Plateau &plateau, CasePosition position);

        

    private :
        const static std::string OVER_TEXTURE_NAME;
        const static std::string SELECT_TEXTURE_NAME;
        const static std::string CIRCLE_TEXTURE_NAME;
        const static std::string PROPRIETAIRE_TEXTURE_NAME;


        const static int COUCHE_MARQUE_PROPRIETAIRE = Terrain::COUCHE+4;
        const static int COUCHE_MARQUE_OVER = Terrain::COUCHE+3;
        const static int COUCHE_MARQUE_SELECT = Terrain::COUCHE+2;
        const static int COUCHE_MARQUE_CIRCLE = Terrain::COUCHE+1;

        int getCouche(TYPE_MARQUE typeMarque);

};