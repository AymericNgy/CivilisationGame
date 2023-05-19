#include "affichable_on_panel.hpp"
#include "SpriteForUI.hpp"
#include "UserInterface.hpp"
#include "../plateau.hpp"

void AffichableOnPanel::setPosition(int i, int j) {
    sprite->setPosition(sf::Vector2f(i, j));
}

Pixel AffichableOnPanel::getPosition() const {
    Pixel pxl;
    pxl.i=sprite->getPosition().x;
    pxl.j=sprite->getPosition().y;
    return pxl;
}



AffichableOnPanel::AffichableOnPanel(Pixel position, int couche, std::string textureName) {
    sprite = new SpriteForUI(textureName,couche,false);
    sprite->setPosition(sf::Vector2f(position.i,position.j));
}


AffichableOnPanel::~AffichableOnPanel() {
    delete sprite;
}

std::string AffichableOnPanel::getTextureFileName() const {
    return sprite->getTextureUI();
}

void AffichableOnPanel::setTextures(std::string textureName) {
    sprite->setTexturesUI(textureName);
}

bool AffichableOnPanel::pixelIsOn(int x, int y) const{
    return sprite->getGlobalBounds().contains(sf::Vector2f(x,y));
}