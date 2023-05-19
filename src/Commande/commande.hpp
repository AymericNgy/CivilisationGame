#ifndef COMMANDE
#define COMMANDE

#include <string>
#include <memory>
#include <iostream>

#include "../UserInterface/affichable_on_panel.hpp"



class Commande : public AffichableOnPanel{
    private:



        static const int COUCHE=30;

    protected:
        std::string info;
        int prix_bois;
        int prix_nourriture;
        int prix_or;





        



    public:

        // renvoie si le joueur actif peut acheter la commande
        bool peutAcheter();

        // renvoie si le joueur actif peut acheter la commande
        // si oui enleve les ressources au joueur actif
        bool acheter();

        //Commande(Pixel position,std::string texturePathName, std::string info);
        Commande(Pixel position,std::string texturePathName, std::string info, int bois, int nourriture, int _or);
        virtual std::string getInfo() const;
        ~Commande();
        virtual void execute() =0;
        bool pixelIsOn(int x, int y) const;

        void prix(int &bois, int &nourriture, int &_or);

           

    
};








#endif