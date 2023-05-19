#include "text_for_ui.hpp"



const std::string TextForUI::FONT_NAME = "Classica-Book.ttf";

TextForUI::TextForUI(int couche, bool moveWithCam,const sf::String& string) : TextForUI(couche,moveWithCam,string,*UserInterface::getInstance().getFont(FONT_NAME)){

}

TextForUI::TextForUI(int couche, bool moveWithCam,const sf::String& string, const sf::Font& font) : DrawableForUI(couche,moveWithCam) ,Text(string,font){

}


void TextForUI::drawOn(sf::RenderWindow &window) {
    window.draw(*this);
}



void TextForUI::setPositionUI(const sf::Vector2f &position) {
    this->setPosition(position);
}