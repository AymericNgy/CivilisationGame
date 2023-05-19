#ifndef BATIMENT
#define BATIMENT

#include <string>
#include "element_joueur.hpp"


class Batiment : public ElementJoueur{
    protected:
        const static int COUCHE = 15;


    public :
        Batiment(std::string textureFileName, std::string info,std::string name,std::string icon_texture_file_name,Joueur_ptr joueurProprietaire);

};






#endif