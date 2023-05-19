#ifndef TEXT_FOR_UI_HPP
#define TEXT_FOR_UI_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable_for_ui.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/String.hpp>


class TextForUI : public sf::Text, public DrawableForUI {



    const static std::string FONT_NAME;

    public :
        TextForUI(int couche, bool moveWithCam,const sf::String& string, const sf::Font& font);
        TextForUI(int couche, bool moveWithCam,const sf::String& string);

        void drawOn(sf::RenderWindow &window);
        // identique a setPosition
        void setPositionUI(const sf::Vector2f &position);
};











#endif