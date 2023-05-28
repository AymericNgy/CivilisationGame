#ifndef HUD
#define HUD

#include "AffichableOnPanel/dashboard.hpp"
#include "AffichableOnPanel/ressources.hpp"
#include "AffichableOnPanel/banner.hpp"
#include "Commande/next_player_arrow.hpp"
#include <memory>



// creer apres que les joueurs soient crees
class Hud {
    private:
        Dashboard dashboard;
        Ressource ressource;
        Banner banner;
        NextPlayerArrow nextPlayerArraow;

        //void updateRessrouces();

        void updateBanner();

        // met a joueur les infos du joueur actif sur le hud (banner et ressource)
        void updateJoueur();




    public:
        Hud();
    
        ~Hud();

        // ---FONCTIONS---

        // RELATIF AU DASHBOARD

        void removeInfoElement();

        void removeInfoNormal();



        // va placer au bonne endroit et detruire les anciennes
        // ne supprime pas les infos sur le dashboard
        // /!\ se charge de detruire les commandes envoyées
        void pushCommandeSquare(ListPtrCommandeSquare_ptr commandes); 

        void pushInfoElement(ElementJoueur *ElementJoueurPourInfo);

        // /!\ se charge de detruire les commandes envoyées ne pas reutiliser les commandes
        void pushCommandes(ListPtrCommandeSquare_ptr commandes, std::string info);

        //detruit les comandeSquare contenu dans commandesSquare
        void cleanCommandeSquare();


        void updateInfoElement();

        bool pixelIsOn(int x, int y)const;

        void updateRessources() {ressource.update();}

        void removeCommande(CommandeSquare* commande) {dashboard.removeCommande(commande);}

        // vide le hud et change le joueur actif affiche
        void changeJoueur();

        // vide le hud des commandes et infos
        void clearAll() {dashboard.clearAll();}

        


};

typedef std::shared_ptr<Hud> Hud_ptr;

















#endif