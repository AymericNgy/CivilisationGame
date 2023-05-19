#include "next_player_arrow.hpp"
#include "../UserInterface/UserInterface.hpp"
#include "../jeu.hpp"

const std::string NextPlayerArrow::TEXTURE_NAME = "next_player_arrow.png";
const std::string NextPlayerArrow::INFO = "Finir son tour";


const int NextPlayerArrow::POSITION_X=UserInterface::WINDOW_WIDTH-NextPlayerArrow::WIDTH-20;
const int NextPlayerArrow::POSITION_Y=UserInterface::WINDOW_HEIGHT-NextPlayerArrow::HEIGHT-20;

NextPlayerArrow::NextPlayerArrow() : Commande(Pixel(POSITION_X,POSITION_Y),TEXTURE_NAME,INFO,0,0,0) {




}


void NextPlayerArrow::execute() {
    Jeu::getInstance().changerJoueur();
}