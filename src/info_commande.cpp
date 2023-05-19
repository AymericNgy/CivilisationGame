#include "info_commande.hpp"
#include <sstream>



const sf::Color InfoCommande::COLOR_TEXT = sf::Color::White;
const sf::Color InfoCommande::COLOR_RECTANGLE = sf::Color::Black;




    //setPosition(sf::Vector2f(Dashboard::POSITION_X,Dashboard::POSITION_Y));
InfoCommande::InfoCommande(int couche) :rectangle(couche,false,sf::Vector2f(0,0)),info(couche,false,""){
    info.setFillColor(COLOR_TEXT);
    info.setCharacterSize(CHARACTER_SIZE);
    info.setLetterSpacing(0.7);
    info.setLineSpacing(0.9);
    rectangle.setFillColor(COLOR_RECTANGLE);



}

void InfoCommande::clear() {
    info.setString("");
    rectangle.setSize(sf::Vector2f(0,0));
}

void InfoCommande::setInfo(int prix_bois, int prix_nourriture, int prix_or,const sf::String &info) {
    std::stringstream ss;
    if (prix_bois>0 ) {
            ss << "bois : " << prix_bois <<"   " ;
    }
    if (prix_nourriture>0 ) {
        ss << "nourriture : " << prix_nourriture<< "   ";
    }
    if (prix_or>0) {
        ss << "or : " << prix_or<< "   ";
    }
    if (!(ss.str()=="")) {
        ss<<"\n";
    }
    std::string info_copie = info;
    ss<<info_copie;

    this->info.setString(ss.str());

    sf::Vector2f dimension_rectangle =sf::Vector2f(this->info.getGlobalBounds().width+20.f,this->info.getGlobalBounds().height+20.f);
    rectangle.setSize(dimension_rectangle);
    
    // poisition pour que l'origine soit en bas durectangle
    sf::Vector2f true_position = sf::Vector2f(POSITION_X, POSITION_Y-dimension_rectangle.y);
    
    this->info.setPositionUI(true_position+sf::Vector2f(5,5));
    rectangle.setPositionUI(true_position);
}

