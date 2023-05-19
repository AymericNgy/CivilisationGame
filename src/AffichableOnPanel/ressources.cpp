#include "ressources.hpp"
#include "../UserInterface/UserInterface.hpp"
#include "../joueur.hpp"
#include "../jeu.hpp"
#include "../UserInterface/text_for_ui.hpp"

const std::string Ressource::TEXTURE_NAME = "ressources.png";


Ressource::Ressource() : AffichableOnPanel(Pixel(0,0),COUCHE,TEXTURE_NAME){
    initInfo();
    _bois=0;
    _nourriture=0;
    _or=0;
    update();
    

}


Ressource::~Ressource() {
    std::cout <<"Ressource::~Ressource()"<<std::endl;
    delete text_bois;
    delete text_nourriture;
    delete text_or;
}

void Ressource::update() {
    Joueur_ptr joueur_actif = Jeu::getInstance().getJoueurActif();
    _bois = joueur_actif->getBois();
    _nourriture = joueur_actif->getNourriture();
    _or =joueur_actif->getOr();

    text_bois->setString(std::to_string(_bois));
    text_nourriture->setString(std::to_string(_nourriture));
    text_or->setString(std::to_string(_or));

}

void Ressource::initInfo() {


    text_bois = new TextForUI(COUCHE+1,false,"");
    text_bois->setPosition(sf::Vector2f(POSITION_BOIS_X,POSITION_BOIS_Y));
    text_bois->setFillColor(sf::Color::White);
    text_bois->setCharacterSize(CHARACTER_SIZE);

    text_nourriture = new TextForUI(COUCHE+1,false,"");
    text_nourriture->setPosition(sf::Vector2f(POSITION_NOURRITURE_X,POSITION_NOURRITURE_Y));
    text_nourriture->setFillColor(sf::Color::White);
    text_nourriture->setCharacterSize(CHARACTER_SIZE);

    text_or = new TextForUI(COUCHE+1,false,"");
    text_or->setPosition(sf::Vector2f(POSITION_OR_X,POSITION_OR_Y));
    text_or->setFillColor(sf::Color::White);
    text_or->setCharacterSize(CHARACTER_SIZE);

    update();
}

