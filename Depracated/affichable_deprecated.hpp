#ifndef AFFICHABLE
#define AFFICHABLE

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>



class Affichable {
    protected :
        double m_positionX, m_positionY;
        std::string m_TextureFileName;
        sf::Sprite sprite;

    

        virtual void setTextureFileName()=0;

    public :
        Affichable() : m_positionX(0), m_positionY(0) {this->setTextureFileName();};
        virtual void getPosition(double &x, double &y) const;
        virtual void setPosition(double x, double y);


};

typedef std::shared_ptr<Affichable> Affichable_ptr;




















#endif 