#ifndef BATIMENT
#define BATIMENT

#include <string>
#include "element_joueur.hpp"


/**
 * \class Batiment
 * \brief classe abstraite representant un batiment
 * 
*/
class Batiment : public ElementJoueur{
    protected:
        const static int COUCHE = 15;

        const static std::string SOUND_NAME_DESTRUCTION;




    public :
        Batiment(std::string textureFileName, std::string info,std::string name,std::string icon_texture_file_name,Joueur_ptr joueurProprietaire);


        std::string soundNameOfDestruction() override {return SOUND_NAME_DESTRUCTION;}

};






#endif