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


class Case {
    private :
        std::set<AffichableOnMap*> elementsOn;
        Joueur_ptr proprietaire;
        CasePosition casePosition;





    public :
        Case(CasePosition casePosition, Plateau &plateau);
        ~Case();
        Case &operator=(const Case& other)=delete;
        Case(const Case& other)=delete;

        // envoie la liste des commandes possibles[!] va plutot etre mis dans le joueur
        // virtual std::list<CommandeCase_ptr> getActionPossible(EtatSelectedCase etatSelectedCase, Joueur &joueur)=0;

        // /!\ DOIT ETRE UTILISE UNIQUEMENT PAR Plateau /!\  .
        void addElementOn(AffichableOnMap *element) {
            elementsOn.insert(element);
            
            };

        // /!\ DOIT ETRE UTILISE UNIQUEMENT PAR Plateau /!\  .
        void removeElementOn(AffichableOnMap *element) {elementsOn.erase(element);}

        std::set<AffichableOnMap*> &getElementsOn();


        int nbElement() const {return elementsOn.size();}

        int nombreElementJoueurOn();

        int nombreElementJoueurOn(Joueur_ptr joueur);

        void setProprietaire(Joueur_ptr proprietaire);

        // renovie s'il y a un batiment construit dessus
        bool batimentsOn();

        Joueur_ptr getProprietaire() const {return proprietaire;}

        CasePosition getPosition() {return casePosition;}


        // ---POUR COMMANDES---

        void _commandeSelectElement();

        void _commandeAcheterCase();

        void _commandeConstuire();



        
        


};

typedef std::shared_ptr<Case> Case_ptr;



#endif