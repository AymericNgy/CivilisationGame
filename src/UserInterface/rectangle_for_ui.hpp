#ifndef RECTANGLE_FOR_UI
#define RECTANGLE_FOR_UI

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable_for_ui.hpp"


class RectangleForUI : public sf::RectangleShape, public DrawableForUI {

    public :
        RectangleForUI(int couche, bool moveWithCam, const sf::Vector2f &size);
        RectangleForUI(int couche, bool moveWithCam, const sf::Vector2f &size, const sf::Color &color);

        void drawOn(sf::RenderWindow &window);
        
        // identique a setPosition
        void setPositionUI(const sf::Vector2f &position);














};

#endif