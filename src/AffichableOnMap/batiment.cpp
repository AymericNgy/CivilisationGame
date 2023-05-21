#include "batiment.hpp"


const std::string Batiment::SOUND_NAME_DESTRUCTION="destruction_batiment.wav";

Batiment::Batiment(std::string textureFileName,std::string info,std::string name,std::string icon_texture_file_name,Joueur_ptr joueurProprietaire) : ElementJoueur(COUCHE,textureFileName,info,name,icon_texture_file_name,joueurProprietaire){
    
}

