#include "menu.hpp"
#include "../UserInterface/UserInterface.hpp"


const std::string Menu::TEXTURE_NAME = "fond_menu.jpg";

Menu::Menu() : AffichableOnPanel(Pixel(POSITION_X,POSITION_Y),COUCHE,TEXTURE_NAME){

}