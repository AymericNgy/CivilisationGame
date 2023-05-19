#ifndef DRAWABLE_FOR_UI_HPP
#define DRAWABLE_FOR_UI_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>


#include "UserInterface.hpp"

typedef std::shared_ptr<sf::Texture> Texture_ptr;


// classe abstraite pour cree des objets affichables sur la fenetre de jeu,
// il peuvent suivre les mouvements de la camera
// drawOn() et setPositionUI() a redefinir dans des classe enfants qui heritent aussi de classes qui heritent de sf::Drawable et shTransformable (Shape,Sprite,text)
class DrawableForUI {
    private:
        // ---FONCTIONS---

        void addToUI() ;
        void removeFromUI();
        
        
        


    protected:

        // --- VARIABLES ---

        // couche d'affichage,
        // plus couche est grand plus le sprite est dessiner au dessus des autres
        // doit etre inferieur a UserInterface::NOMBRE_COUCHE_SPRITES
        int couche; 

        CasePosition casePosition;

        bool moveWithCam;



    public:
        //cree un drawable en position de case 0 0 sur le plateau
        DrawableForUI(int couche, bool moveWithCam);

        ~DrawableForUI();

        DrawableForUI(const DrawableForUI& other) = delete;
        DrawableForUI& operator=(DrawableForUI& other) = delete;

        // fonction a redefinir dans des classe enfants qui heritent de cette classe et qui heritent de sf::Drawable
        virtual void drawOn(sf::RenderWindow &window)=0;
        // fonction a redefinir dans des classe enfants qui heritent de cette classe et qui heritent de sf::Transformable
        virtual void setPositionUI(const sf::Vector2f &position)=0;


        const CasePosition &getCasePosition() const;
        
        // utile que si moveWithCam=true
        void setCasePosition(CasePosition casePosition);

        // permet de mettre a jour le sprite en fonction de la position de la cam et de sa position sur le cadrillage
        // fonctionnelle que si moveWithCam=true
        void updateFromCam();

        int getCouche()const;

};




























#endif 