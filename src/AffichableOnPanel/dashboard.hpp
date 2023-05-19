#ifndef DASHBOARD
#define DASHBOARD

#include "../UserInterface/affichable_on_panel.hpp"
#include "../UserInterface/UserInterface.hpp"
#include <list>
#include <memory>
#include "../UserInterface/text_for_ui.hpp"

class CommandeSquare;
class ElementJoueur;

typedef std::shared_ptr<std::list<CommandeSquare*>> ListPtrCommandeSquare_ptr;


class Dashboard : public AffichableOnPanel {
    public :
            // ---CONSTANTES---

        // ---TAILLES SUR IMAGE---
        static const int WIDTH = 1032; // en pxl
        static const int HEIGHT = 213; //en pxl

        static const int POSITION_X = 0; // en pxl
        static const int POSITION_Y = UserInterface::WINDOW_HEIGHT-Dashboard::HEIGHT;// en pxl
    private :
        // ---CONSTANTES---



        // QUADRILLAGE

        static const int ORIGINE_QUADRILLAGE_X = POSITION_X+28; //pxl
        static const int ORIGINE_QUADRILLAGE_Y = POSITION_Y+26;

        static const int TAILLE_CARRE = 48; // pxl

        static const int TAILLE_INTERSTICE = 8; //interstice entre carre

        static const int NOMBRE_CASE_X = 5;
        static const int NOMBRE_CASE_Y = 3;


        // INFO

        static const int ORIGINE_INFO_X = POSITION_X + 379; //pxl
        static const int ORIGINE_INFO_Y = POSITION_Y + 35; //pxl

        static const int ORIGINE_INFO_PARTIE_2_X = POSITION_X + 705; //pxl

        static const int CHARACTER_SIZE_NOM = 22;
        static const int CHARACTER_SIZE_INFO_ELEMENT = 15;
        static const int CHARACTER_SIZE_INFO = 19;



        static const int COUCHE = 20;

        static const std::string TEXTURE_NAME;
        

        // ---ATTRIBUTS---

        // ---CARRES ACTION ---
        
        std::list<CommandeSquare*> commandesSquare;


        // --- INFOS ---


        // cree avec instance avec new, detruit avec instance avec delete 
        // [?] DEMANDER POURQUOI MARCHE PAS D'AVOIR UN ATTRIBUT sf::Text
        TextForUI *nom_element_info; 
        AffichableOnPanel *icon_element_info;
        TextForUI *vie_element_info; 
        TextForUI *tour_element_info; 
        TextForUI *nombre_case_deplacement;
        TextForUI *nombreDegat;
        TextForUI *distanceAttaque;
        TextForUI *creationRessource;
        
        TextForUI *info_normal; 

        // element dont les infos vont etre mises sur le dashBoard
        ElementJoueur *elementJoueurPourInfo;

        
        // ---FONCTIONS---
        


        // /!\ a ne faire que dans le constructeur
        void initInfo();



        void pushInfos(std::string info);




    public:

        


        // ---FONCTIONS---

        void removeInfoElement();

        void removeInfoNormal();



        // va placer au bonne endroit et detruire les anciennes
        // ne supprime pas les infos sur le dashboard
        // /!\ se charge de detruire les commandes envoyées
        void pushCommandeSquare(ListPtrCommandeSquare_ptr commandes); 

        void pushInfoElement(ElementJoueur *ElementJoueurPourInfo);

        // /!\ se charge de detruire les commandes envoyées ne pas reutiliser les commandes
        void pushCommandes(ListPtrCommandeSquare_ptr commandes, std::string info);

        //detruit les comandeSquare contenu dans commandesSquare (avec delete)
        void cleanCommandeSquare();


        void updateInfoElement();

        // /!\ va detruire la commande avec delete
        // utile pour que les commandes puissent se retirer a la fin de leur execute()
        void removeCommande(CommandeSquare* commande);

        // eneleve toute les infos et commandes du Hud
        void clearAll();




        Dashboard();

        ~Dashboard();





};

























#endif 
