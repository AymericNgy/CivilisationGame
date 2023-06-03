#ifndef INFO_COMMAND
#define INFO_COMMAND


#include "UserInterface/text_for_ui.hpp"
#include "UserInterface/rectangle_for_ui.hpp"
#include "AffichableOnPanel/dashboard.hpp"

/**
 * \class InfoCommande
 * \brief permet d'afficher les infos sur la commande en cours \n
 * la commande se fait au dessus du dashboard
*/
class InfoCommande {
    private :

    /**
     * \brief couleur du rectangle de l'info
    */
    const static sf::Color COLOR_RECTANGLE;

    /**
     * \brief couleur du texte de l'info
    */
    const static sf::Color COLOR_TEXT;

    /**
     * \brief taille du texte de l'info
    */
    static const int CHARACTER_SIZE = 18;

    /**
     * \brief position du rectangle de l'info celon x
    */
    static const int POSITION_X = Dashboard::POSITION_X;

    /**
     * \brief position du rectangle de l'info celon y
    */
    static const int POSITION_Y = Dashboard::POSITION_Y;

    /**
     * \brief rectangle englobant l'info
    */
    RectangleForUI rectangle;

    /**
     * \brief texte de l'info
    */
    TextForUI info;

    
    public :

        /**
         * \brief constructeur
         * \param couche couche d'affichage de l'info
        */
        InfoCommande(int couche);
        
        /**
         * rend l'info vide (transparente)
        */
        void clear();

        /**
         * \brief modifie l'info
         * \param prix_bois prix en bois de la commande
         * \param prix_nourriture prix en nourriture de la commande
         * \param prix_or prix en or de la commande
         * \param info texte de l'info
        */
        void setInfo(int prix_bois, int prix_nourriture, int prix_or,const sf::String &info);



        




};







#endif
