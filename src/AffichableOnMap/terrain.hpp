#ifndef TERRAIN
#define TERRAIN


#include "../UserInterface/affichable_on_map.hpp"
#include <string>

/**
 * \class Terrain
 * \brief terrain sur chaque case du plateau
*/
class Terrain : public AffichableOnMap {
    



    

    protected:
        
        static const std::string TEXTURE_NAME;
    public:
        static const int COUCHE = 1;
        Terrain(Plateau &plateau, CasePosition casePosition) : AffichableOnMap(plateau,casePosition,COUCHE,TEXTURE_NAME) {
        
        };
        




};



#endif