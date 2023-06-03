#ifndef TEXT_FOR_UI_HPP
#define TEXT_FOR_UI_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable_for_ui.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/String.hpp>

/**
 * \class TextForUI
 * \brief Classe qui permet de créer un texte pour l'interface utilisateur \n
 * comme implemente DrawableForUI, il s'ajoute automatiquement a l'interface utilisateur
*/
class TextForUI : public sf::Text, public DrawableForUI {


    /**
     * \brief Nom de la police de caractere utilisee pour les textes de l'interface utilisateur
    */
    const static std::string FONT_NAME;

    public :
        /**
         * \brief Constructeur de TextForUI
         * \param couche Couche sur laquelle le texte sera affiche
         * \param moveWithCam Si true, le texte se deplacera avec la camera
         * \param string Texte a afficher
         * \param font Police de caractere a utiliser
        */
        TextForUI(int couche, bool moveWithCam,const sf::String& string, const sf::Font& font);

        /**
         * \brief Constructeur de TextForUI
         * \param couche Couche sur laquelle le texte sera affiche
         * \param moveWithCam Si true, le texte se deplacera avec la camera
         * \param string Texte a afficher
        */
        TextForUI(int couche, bool moveWithCam,const sf::String& string);


        void drawOn(sf::RenderWindow &window) override;


        /**
         * \brief identique a setPosition
        */
        void setPositionUI(const sf::Vector2f &position) override;
};











#endif