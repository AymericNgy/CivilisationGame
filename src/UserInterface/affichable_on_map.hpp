#ifndef AFFICHABLE_ON_MAP
#define AFFICHABLE_ON_MAP


#include "UserInterface.hpp"
#include "SpriteForUI.hpp"
#include "../plateau.hpp"


class Jeu;


typedef std::shared_ptr<std::set<AffichableOnMap*>> SetPtrAffichableOnMap_ptr;


// classe qui permet a une classe d'etre affichable sur la map
// elle gere le deplacement sur la map du jeu de l'objet
// on utilise des pointeurs pour pouvoire faire des delete quand on veut detruire l'objet
// utilise des AffichableOnMap que pendant la duree d'existance du plateau
class AffichableOnMap
{
    protected:
        
        // permet aux instances de se deplacer tout seul sur le plateau
        Plateau *plateau;


        SpriteForUI sprite;
        //std::set<CommandeAffichableOnMap_ptr> actionsPossible; DEPRACATED => beaucoup plus logiqu de creer a chaque fois





    public:
        virtual std::string getTextureFileName() const {return sprite.getTextureUI();}

        virtual void moveToPosition(CasePosition casePosition); 

        virtual CasePosition getCasePosition() const {return sprite.getCasePosition();}

        // /!\ ne pas utiliser lors de la creation de Jeu, car cette fonction fait appelle à Jeu::getInstance()
        AffichableOnMap(CasePosition casePosition, int couche, std::string textureName);

        // A utiliser lors de la creation de Jeu
        AffichableOnMap(Plateau &plateau, CasePosition casePosition, int couche, std::string textureName);

        virtual ~AffichableOnMap();

        void setTextures(std::string textureName);

        void setColor(const sf::Color &couleur) {sprite.setColor(couleur);}

        
};


typedef std::shared_ptr<AffichableOnMap> AffichableOnMap_ptr;



#endif