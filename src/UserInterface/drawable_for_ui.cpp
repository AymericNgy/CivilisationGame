#include "drawable_for_ui.hpp"


void DrawableForUI::addToUI() {
    UserInterface &ui = UserInterface::getInstance();
    ui.addDrawable(this);
}


void DrawableForUI::removeFromUI() {
    UserInterface &ui = UserInterface::getInstance();
    ui.removeDrawable(this);
}

DrawableForUI::DrawableForUI(int couche, bool moveWithCam) {
    this->couche=couche;


    casePosition.x = 0;
    casePosition.y = 0;

    this->moveWithCam = moveWithCam;

    addToUI();

}


DrawableForUI::~DrawableForUI() {
    removeFromUI();
}

const CasePosition &DrawableForUI::getCasePosition() const {
    return this->casePosition;
}

void DrawableForUI::setCasePosition(CasePosition casePosition) {
    this->casePosition.x = casePosition.x;
    this->casePosition.y = casePosition.y;
}

void DrawableForUI::updateFromCam() {

    if (this->moveWithCam) {
        UserInterface &ui = UserInterface::getInstance();
        Pixel pixel = ui.case2pixel(this->casePosition.x,this->casePosition.y);
        sf::Vector2f position(pixel.i, pixel.j);

        this->setPositionUI(position);
        
    }
}

int DrawableForUI::getCouche()const {
    return couche;
}



