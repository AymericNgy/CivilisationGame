#ifndef COMMANDE_SQUARE
#define COMMANDE_SQUARE

#include <string>
#include <memory>
#include <list>

#include "commande.hpp"





/**
 * \class CommandeSquare
 * \brief commande qu'on peut rajouter en bas à gauche du Dahsboard et qui sont carrees
 * le dashBoard va se charger de detruire les commandes quand elles ne sont plus utiles
 * /!\ les CommandeSquare doivent donc etre cree avec new et ne plus etre utilise apres le passage au dashBoard
*/
class CommandeSquare: public Commande { 
    protected :
        const int static HEIGHT = 36; // pxl
        const int static WIIDTH = 36; // pxl
    
    public :

        /**
         * \brief constructeur
         * \param texturePathName chemin vers la texture de la commande
         * \param info information sur la commande
         * \param bois prix en bois de la commande
         * \param nourriture prix en nourriture de la commande
         * \param _or prix en or de la commande
        */
        CommandeSquare(std::string texturePathName, std::string info, int bois, int nourriture, int _or);

};

typedef std::shared_ptr<std::list<CommandeSquare*>> ListPtrCommandeSquare_ptr;




#endif