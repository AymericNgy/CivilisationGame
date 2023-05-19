#ifndef UNITE
#define UNITE

#include <string>
#include "element_joueur.hpp"
#include "interface_se_deplacer.hpp"


class Unite : public ElementJoueur, public InterfaceSeDeplacer{
    protected :
        const static int COUCHE = 18;

    public :
        Unite(std::string textureFileName, std::string info,std::string name,std::string icon_texture_file_name,Joueur_ptr joueurProprietaire);

 


};






#endif