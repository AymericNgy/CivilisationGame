#ifndef AFFICHABLE_ON_PANEL
#define AFFICHABLE_ON_PANEL


#include <string>
#include <memory>




class Jeu;
class Pixel;
class SpriteForUI;

// classe qui permet a une classe d'etre affichable sur la map
// elle gere le deplacement sur la map du jeu de l'objet
// on utilise des pointeurs pour pouvoire faire des delete quand on veut detruire l'objet
class AffichableOnPanel
{
    protected:



        SpriteForUI *sprite; // [?] utilise un pointeur sinon probleme pour les includes, permet d'utiliser class SpriteForUI; => merci le compilateur C++
        //std::set<CommandeAffichableOnMap_ptr> actionsPossible; DEPRACATED => beaucoup plus logiqu de creer a chaque fois

 



    public:
        virtual std::string getTextureFileName() const;

        virtual void setPosition(int i, int j); 

        virtual Pixel getPosition() const;

        AffichableOnPanel(Pixel position, int couche, std::string textureName);

        ~AffichableOnPanel();

        void setTextures(std::string textureName);

        // teste si le pixel de coordonnes (x,y) fait partie du sprite
        bool pixelIsOn(int x, int y) const;


        
};


typedef std::shared_ptr<AffichableOnPanel> AffichableOnPanel_ptr;



#endif