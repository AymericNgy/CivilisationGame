#include "commande.hpp"
#include "commande_square.hpp"
#include "../UserInterface/UserInterface.hpp"


CommandeSquare::CommandeSquare(std::string texturePathName, std::string info, int bois, int nourriture, int _or) : Commande(Pixel(0,0),texturePathName,info,bois,nourriture,_or) {

}