#ifndef SPRITE_FOR_UI
#define SPRITE_FOR_UI



#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>


#include "UserInterface.hpp"
#include "SpriteForUI.hpp"
#include "drawable_for_ui.hpp"



typedef std::shared_ptr<sf::Texture> Texture_ptr;



class SpriteForUI : public sf::Sprite, public DrawableForUI{
    protected:

        // --- VARIABLES ---


        Texture_ptr texture;

        std::string textureName;




        

    public:
        //cree un sprite en position de case 0 0 sur le plateau
        SpriteForUI(std::string textureName,int couche, bool moveWithCam);




        //permet de recuperer la texture depuis la UI
        void setTexturesUI(std::string textureName);

        std::string getTextureUI() const {return textureName;}

        void drawOn(sf::RenderWindow &window);
        void setPositionUI(const sf::Vector2f &position);


};



typedef std::shared_ptr<SpriteForUI> SpriteForUI_ptr;




#endif