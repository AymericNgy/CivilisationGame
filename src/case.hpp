#ifndef CASE
#define CASE


#include <list>
#include <memory>
#include <set>
#include <iostream>



class AffichableOnMap;
class Joueur;
class Terrain;
class Plateau;
class AcheterCase;


typedef std::shared_ptr<Joueur> Joueur_ptr;

/**
 * \class CasePosition
 * \brief position d'une case sur le plateau
*/
class CasePosition {

	public:

		int x;
		int y;

        CasePosition() : CasePosition(0,0) {};

		CasePosition(int x, int y) {
				this->x = x;
				this->y = y;
			}
		
		//permet de mettre CasePosition dans un set
		bool operator<(const CasePosition& other) const;

		
		CasePosition &operator=(const CasePosition& other);
	
};

std::ostream& operator<<(std::ostream& os, const CasePosition &case_);



/**
 * \class Case
 * \brief Case du plateau \n
 * Permet de savoir ce qu'il y a sur la case (AffichableOnMap), et qui est le proprietaire de la case
*/
class Case {
    private :

        // ---ATTRIBUTS---

        /**
         * \brief liste des elements sur la case
        */
        std::set<AffichableOnMap*> elementsOn;

        /**
         * \brief proprietaire de la case
        */
        Joueur_ptr proprietaire;

        /**
         * \brief position de la case sur le plateau
        */
        CasePosition casePosition;





    public :

        // ---CONSTRUCTEURS---
        /**
         * \brief Constructeur de Case
         * \param casePosition position de la case sur le plateau
         * \param plateau plateau sur lequel se trouve la case
        */
        Case(CasePosition casePosition, Plateau &plateau);

        ~Case();

        Case &operator=(const Case& other)=delete;

        Case(const Case& other)=delete;


        // ---METHODES---


        /**
         * \brief ajoute un element sur la case
         * // /!\ DOIT ETRE UTILISE UNIQUEMENT PAR Plateau /!\  .
         * \sa Plateau::addElement
        */
        void addElementOn(AffichableOnMap *element) {
            elementsOn.insert(element);
            
            };


        /**
         * \brief enleve un element sur la case
         * /!\ DOIT ETRE UTILISE UNIQUEMENT PAR Plateau /!\  .
         * \sa Plateau::removeElement
        */
        void removeElementOn(AffichableOnMap *element) {elementsOn.erase(element);}

        /**
         * \brief renvoie les AffichableOnMap sur la case
        */
        std::set<AffichableOnMap*> &getElementsOn();

        /**
         * \brief renvoie le nombre d'element sur la case
        */
        int nbElement() const {return elementsOn.size();}

        /**
         * \brief renvoie le nombre d'element sur la case de type ElementJoueur
        */
        int nombreElementJoueurOn();

        /**
         * \brief renvoie le nombre d'element sur la case de type ElementJoueur appartenant au joueur 'joueur'
         * \param joueur joueur dont on veut connaitre le nombre d'element sur la case
        */
        int nombreElementJoueurOn(Joueur_ptr joueur);

        /**
         * \brief definit le proprietaire de la case
         * \param proprietaire nouveau proprietaire de la case
        */
        void setProprietaire(Joueur_ptr proprietaire);


        /**
         * \brief renvoie si il y a un batiment construit sur la case
         * \return true si il y a un batiment construit sur la case, false sinon
        */
        bool batimentsOn();

        /**
         * \brief renvoie le proprietaire de la case
        */
        Joueur_ptr getProprietaire() const {return proprietaire;}

        /**
         * \brief renvoie la position de la case sur le plateau
        */
        CasePosition getPosition() {return casePosition;}


        // ---POUR COMMANDES---

        /**
         * \brief permet de mettre dans le HUD les commandes pour selectionner 
         * tous les elements appartenant au joueur actif sur la case \n
         * si il n'y a qu'un seul element sur la case, la commande est directement executee
        */
        void _commandeSelectElement();

        /**
         * \brief definit le joueur actif comme proprietaire de la case
        */
        void _commandeAcheterCase();

        /**
         * \brief permet de mettre dans le HUD les commandes pour construire chaque batiment disponible dans le jeu, 
         * sauf l'hotel de ville, sur la case \n
        */
        void _commandeConstuire();



        
        


};

typedef std::shared_ptr<Case> Case_ptr;



#endif