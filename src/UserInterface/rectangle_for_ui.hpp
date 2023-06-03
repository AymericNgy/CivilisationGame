#ifndef RECTANGLE_FOR_UI
#define RECTANGLE_FOR_UI

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable_for_ui.hpp"

/**
 * \class RectangleForUI
 * \brief Classe qui permet de créer un rectangle pour l'interface utilisateur \n
 * comme implemente DrawableForUI, il s'ajoute automatiquement a l'interface utilisateur
*/
class RectangleForUI : public sf::RectangleShape, public DrawableForUI {

    public :
        /**
         * \brief Constructeur de RectangleForUI
         * \param couche Couche sur laquelle le rectangle sera affiche
         * \param moveWithCam Si true, le rectangle se deplacera avec la camera
         * \param size Taille du rectangle
        */
        RectangleForUI(int couche, bool moveWithCam, const sf::Vector2f &size);

        /**
         * \brief Constructeur de RectangleForUI
         * \param couche Couche sur laquelle le rectangle sera affiche
         * \param moveWithCam Si true, le rectangle se deplacera avec la camera
         * \param size Taille du rectangle
         * \param color Couleur du rectangle
        */
        RectangleForUI(int couche, bool moveWithCam, const sf::Vector2f &size, const sf::Color &color);

        void drawOn(sf::RenderWindow &window) override;
        

        /**
         * \brief identique a setPosition
        */
        void setPositionUI(const sf::Vector2f &position) override;














};

#endif