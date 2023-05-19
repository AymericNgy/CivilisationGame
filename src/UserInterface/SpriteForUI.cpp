#include "SpriteForUI.hpp"
#include "../case.hpp"
#include "UserInterface.hpp"
#include "../case.hpp"  



// nombre sprite crees,
// permetra d'identifier chaque sprite pour pouvoir le retrouver dans l'UserInterface






SpriteForUI::SpriteForUI(std::string textureName,int couche, bool moveWithCam) : DrawableForUI(couche,moveWithCam) {
    setTexturesUI(textureName);
}



void SpriteForUI::setTexturesUI(std::string textureName) {
    this->textureName = textureName;
    UserInterface &ui = UserInterface::getInstance();
    this->texture = ui.getTexture(textureName);
    this->setTexture(*texture);
    sf::IntRect textureRect(0, 0, texture->getSize().x, texture->getSize().y); 
    this->setTextureRect(textureRect); //permet de mettre a jour la taille de la texture
    
}







void SpriteForUI::drawOn(sf::RenderWindow &window) {
    window.draw(*this);
}

void SpriteForUI::setPositionUI(const sf::Vector2f &position) {
    this->setPosition(position);
}



