#ifndef HUD
#define HUD

#include "AffichableOnPanel/dashboard.hpp"
#include "AffichableOnPanel/ressources.hpp"
#include "AffichableOnPanel/banner.hpp"
#include "Commande/next_player_arrow.hpp"
#include <memory>




/**
 * \class Hud
 * \brief permet d'afficher les infos sur le joueur actif \n
 * /!\ a creer apres que les joueurs soient crees
*/
class Hud {
    private:

        // ---ATTRIBUTS---

        /**
         * \brief dashboard du hud \n
         * endroit ou se present les commandes et leurs descriptions
        */
        Dashboard dashboard;

        /**
         * \brief ressource du joueur actif \n
        */
        Ressource ressource;

        /**
         * \brief banner de la couleur du joueur actif \n
        */
        Banner banner;

        /**
         * \brief fleche permettant de changer le joueur actif \n
        */
        NextPlayerArrow nextPlayerArraow;

        // ---FONCTIONS---
        
        /**
         * \brief met a jour la banner en la couleur du joueur actif \n
        */
        void updateBanner();


        /**
         * \brief met a joueur les infos du joueur actif sur le hud (banner et ressource) \n
        */
        void updateJoueur();




    public:
        // ---CONSTRUCTEUR/DESTRUCTEUR---

        Hud();
    
        ~Hud();

        // ---FONCTIONS---

        // RELATIF AU DASHBOARD

        /**
         * \brief enleve les infos d'un element sur le dashboard \n
         * \sa ElementJoueur
        */
        void removeInfoElement();

        /**
         * \brief enleve les infos sur le dashboard \n
        */
        void removeInfoNormal();




        /**
         * \brief va placer au bonne endroit les commandes et detruire les anciennes \n
         * ne supprime pas les infos sur le dashboard \n
         * /!\ se charge de detruire les commandes envoyées ne pas reutiliser les commandes
         * \param commandes commandes a afficher
        */
        void pushCommandeSquare(ListPtrCommandeSquare_ptr commandes); 

        /**
         * \brief affiche les infos d'un element sur le dashboard \n
         * \sa ElementJoueur
         * \param ElementJoueurPourInfo element dont on veut afficher les infos
        */
        void pushInfoElement(ElementJoueur *ElementJoueurPourInfo);


        /**
         * \brief va placer au bonne endroit les commandes et detruire les anciennes \n
         * change les infos sur le dashboard \n
         * /!\ se charge de detruire les commandes envoyées ne pas reutiliser les commandes
         * \param commandes commandes a afficher
         * \param info info a afficher
        */
        void pushCommandes(ListPtrCommandeSquare_ptr commandes, std::string info);


        /**
         * \brief detruit les comandeSquare contenu dans commandesSquare \n
        */
        void cleanCommandeSquare();

        /**
         * \brief met a jour les infos sur le dashboard \n
        */
        void updateInfoElement();

        /**
         * \brief verifie si le pixel en parametre est sur le hud \n
         * \param x coordonnee x du pixel
         * \param y coordonnee y du pixel
        */
        bool pixelIsOn(int x, int y)const;

        /**
         * \brief met a jour les ressources du joueur actif \n
        */
        void updateRessources() {ressource.update();}

        /**
         * \brief enleve une commande du dashboard \n
         * /!\ va detruire la commande avec delete
         * utile pour que les commandes puissent se retirer a la fin de leur execute()
        */
        void removeCommande(CommandeSquare* commande) {dashboard.removeCommande(commande);}




        /**
         * \brief vide le hud et change le joueur actif affiche \n
        */
        void changeJoueur();


        /**
         * \brief vide le hud des commandes et infos \n
        */
        void clearAll() {dashboard.clearAll();}

        


};

typedef std::shared_ptr<Hud> Hud_ptr;

















#endif