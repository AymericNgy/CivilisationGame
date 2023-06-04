#ifndef COMMANDE
#define COMMANDE

#include <string>
#include <memory>
#include <iostream>

#include "../UserInterface/affichable_on_panel.hpp"


/**
 * \class Commande
 * \brief classe abstraite permettant de creer des commandes
 * 
*/
class Commande : public AffichableOnPanel{
    private:



        static const int COUCHE=30;

    protected:
        std::string info;
        int prix_bois;
        int prix_nourriture;
        int prix_or;





        



    public:



        /**
         * \brief renvoie si le joueur actif peut acheter la commande
        */
        bool peutAcheter();


        /**
         * \brief renvoie si le joueur actif peut acheter la commande \n
         * si oui enleve les ressources au joueur actif
        */
        bool acheter();


        /**
         * \brief constructeur
         * \param position position de la commande
         * \param texturePathName chemin vers la texture de la commande
         * \param info information sur la commande
         * \param bois prix en bois de la commande
         * \param nourriture prix en nourriture de la commande
         * \param _or prix en or de la commande
        */
        Commande(Pixel position,std::string texturePathName, std::string info, int bois, int nourriture, int _or);
        virtual std::string getInfo() const;
        ~Commande();
        virtual void execute() =0;
        bool pixelIsOn(int x, int y) const;

        /**
         * \brief renvoie le prix en bois, nourriture et or de la commande
         * \param bois prix en bois de la commande
         * \param nourriture prix en nourriture de la commande
         * \param _or prix en or de la commande
        */
        void prix(int &bois, int &nourriture, int &_or);

           

    
};








#endif