#include "rectangle_for_ui.hpp"

RectangleForUI::RectangleForUI(int couche, bool moveWithCam, const sf::Vector2f &size) : RectangleForUI(couche,moveWithCam,size,sf::Color::Black){

}

RectangleForUI::RectangleForUI(int couche, bool moveWithCam, const sf::Vector2f &size, const sf::Color &color) : DrawableForUI(couche,moveWithCam) ,RectangleShape(size){
    this->setFillColor(color);
}

void RectangleForUI::drawOn(sf::RenderWindow &window) {
    window.draw(*this);
}

void RectangleForUI::setPositionUI(const sf::Vector2f &position) {
    this->setPosition(position);
}