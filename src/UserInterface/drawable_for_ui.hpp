#ifndef DRAWABLE_FOR_UI_HPP
#define DRAWABLE_FOR_UI_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>


#include "UserInterface.hpp"

typedef std::shared_ptr<sf::Texture> Texture_ptr;



/**
 * \class DrawableForUI
 * \brief Classe abstraite pour cree des objets affichables sur la fenetre de jeu, \n
 * il peuvent suivre les mouvements de la camera \n
 * drawOn() et setPositionUI() a redefinir dans des classe enfants qui heritent aussi de classes qui heritent de sf::Drawable et sf::Transformable (Shape,Sprite,text)
*/
class DrawableForUI {
    private:
        // ---FONCTIONS---

        /**
         * \brief Ajoute le sprite a l'interface utilisateur
        */
        void addToUI() ;

        /**
         * \brief Retire le sprite de l'interface utilisateur
        */
        void removeFromUI();
        
        
        


    protected:

        // --- VARIABLES ---


        /**
         * \brief Couche d'affichage \n 
         * Plus couche est grand plus le sprite est dessiner au dessus des autres \n
         * doit etre inferieur a UserInterface::NOMBRE_COUCHE_SPRITES
        */
        int couche; 

        /**
         * \brief Si true, le sprite se deplacera avec la camera
        */
        bool moveWithCam;

        /**
         * \brief position sur la case
         * utile que si sprite est sur une case
         * ce sont les \sa AffichabeOnMap qui implement des sprites sur des cases
        */
        CasePosition casePosition;





    public:
        /**
         * \brief Constructeur de DrawableForUI \n
         * cree un drawable en position de case 0 0 sur le plateau
        */
        DrawableForUI(int couche, bool moveWithCam);

        ~DrawableForUI();

        DrawableForUI(const DrawableForUI& other) = delete;
        DrawableForUI& operator=(DrawableForUI& other) = delete;


        /**
         * \brief Dessine le sprite sur la fenetre de jeu
         * fonction a redefinir dans des classe enfants qui heritent de cette classe et qui heritent de sf::Drawable
        */
        virtual void drawOn(sf::RenderWindow &window)=0;

        
        /**
         * \brief Met a jour la position du sprite sur la fenetre de jeu
         * fonction a redefinir dans des classe enfants qui heritent de cette classe et qui heritent de sf::Transformable
        */
        virtual void setPositionUI(const sf::Vector2f &position)=0;

        /**
         * \brief renvoie la position du drawable sur le plateau
        */
        const CasePosition &getCasePosition() const;
        


        /**
         * \brief Met a jour la position du sprite sur le plateau
        */
        void setCasePosition(CasePosition casePosition);


        /**
         * \brief permet de mettre a jour le sprite en fonction de la position de la cam et de sa position sur le cadrillage \n
         * fonctionnelle que si moveWithCam=true
        */
        void updateFromCam();

        /**
         * \brief renvoie la couche d'affichage
        */
        int getCouche()const;

};




























#endif 