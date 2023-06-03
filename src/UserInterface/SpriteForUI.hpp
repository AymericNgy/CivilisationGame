#ifndef SPRITE_FOR_UI
#define SPRITE_FOR_UI



#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>


#include "UserInterface.hpp"
#include "SpriteForUI.hpp"
#include "drawable_for_ui.hpp"



typedef std::shared_ptr<sf::Texture> Texture_ptr;


/**
 * \class SpriteForUI
 * \brief Classe qui permet de créer un sprite pour l'interface utilisateur \n
 * comme implemente DrawableForUI, il s'ajoute automatiquement a l'interface utilisateur
*/
class SpriteForUI : public sf::Sprite, public DrawableForUI{
    protected:

        // --- VARIABLES ---

        /**
         * \brief Texture du sprite
        */
        Texture_ptr texture;

        /**
         * \brief Nom de la texture du sprite
        */
        std::string textureName;




        

    public:
        
        /**
         * \brief Constructeur de SpriteForUI
         * cree un sprite en position de case 0 0 sur le plateau
         * \param textureName Nom de la texture du sprite
         * \param couche Couche sur laquelle le sprite sera affiche
         * \param moveWithCam Si true, le sprite se deplacera avec la camera
        */
        SpriteForUI(std::string textureName,int couche, bool moveWithCam);





        /**
         * \brief change la texture du sprite
         * recupere la texture depuis la UI
        */
        void setTexturesUI(std::string textureName);

        /**
         * \brief recupere la texture du sprite
        */
        std::string getTextureUI() const {return textureName;}


        void drawOn(sf::RenderWindow &window) override;
        
        void setPositionUI(const sf::Vector2f &position) override;


};



typedef std::shared_ptr<SpriteForUI> SpriteForUI_ptr;




#endif