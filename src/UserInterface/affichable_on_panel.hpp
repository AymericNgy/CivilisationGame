#ifndef AFFICHABLE_ON_PANEL
#define AFFICHABLE_ON_PANEL


#include <string>
#include <memory>




class Jeu;
class Pixel;
class SpriteForUI;


/**
 * \class AffichableOnPanel
 * \brief Classe abstraite qui permet a une classe d'etre affichable de facon fixe sur le panel
 * elle gere le deplacement sur le panel du jeu de l'objet
 * on utilise des pointeurs pour pouvoire faire des delete quand on veut detruire l'objet
*/
class AffichableOnPanel
{
    protected:


        // ---ATTRIBUTS---
        /**
         * \brief sprite de l'objet
        */
        SpriteForUI *sprite; 

 



    public:
        /**
         * \brief reucperer la texture du sprite
        */
        virtual std::string getTextureFileName() const;

        /**
         * \brief deinir la position du sprite
        */
        virtual void setPosition(int i, int j); 

        virtual Pixel getPosition() const;

        /**
         * \brief constructeur
         * \param position position du sprite
         * \param couche couche du sprite
         * \param textureName nom de la texture du sprite
        */
        AffichableOnPanel(Pixel position, int couche, std::string textureName);

        ~AffichableOnPanel();

        void setTextures(std::string textureName);


        /**
         * \brief teste si le pixel de coordonnes (x,y) fait partie du sprite
        */
        bool pixelIsOn(int x, int y) const;


        
};


typedef std::shared_ptr<AffichableOnPanel> AffichableOnPanel_ptr;



#endif