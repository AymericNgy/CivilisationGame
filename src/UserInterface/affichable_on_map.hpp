#ifndef AFFICHABLE_ON_MAP
#define AFFICHABLE_ON_MAP


#include "UserInterface.hpp"
#include "SpriteForUI.hpp"
#include "../plateau.hpp"


class Jeu;


typedef std::shared_ptr<std::set<AffichableOnMap*>> SetPtrAffichableOnMap_ptr;



/**
 * \class AffichableOnMap
 * \brief Classe abstraite qui permet a une classe d'etre affichable sur la map
 * elle gere le deplacement sur la map du jeu de l'objet
 * on utilise des pointeurs pour pouvoire faire des delete quand on veut detruire l'objet
 * utilise des AffichableOnMap que pendant la duree d'existance du plateau
*/
class AffichableOnMap
{
    protected:
        

        /**
         * \brief pointeur vers le plateau
        */
        Plateau *plateau;

        /**
         * \brief sprite de l'objet
        */
        SpriteForUI sprite;




    public:
        virtual std::string getTextureFileName() const {return sprite.getTextureUI();}

        virtual void moveToPosition(CasePosition casePosition); 

        virtual CasePosition getCasePosition() const {return sprite.getCasePosition();}


        /**
         * \brief constructeur \n
         *  /!\ ne pas utiliser lors de la creation de Jeu, car cette fonction fait appelle à Jeu::getInstance()
        */
        AffichableOnMap(CasePosition casePosition, int couche, std::string textureName);


        /**
         * \brief constructeur \n
         *  A utiliser lors de la creation de Jeu
        */
        AffichableOnMap(Plateau &plateau, CasePosition casePosition, int couche, std::string textureName);

        virtual ~AffichableOnMap();


        void setTextures(std::string textureName);

        void setColor(const sf::Color &couleur) {sprite.setColor(couleur);}

        
};


typedef std::shared_ptr<AffichableOnMap> AffichableOnMap_ptr;



#endif