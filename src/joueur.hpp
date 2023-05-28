#ifndef JOUEUR
#define JOUEUR

#include "AffichableOnMap/element_joueur.hpp"
#include <set>
#include <memory>


typedef std::shared_ptr<Joueur> Joueur_ptr;
typedef std::shared_ptr<std::list<CommandeSquare*>> ListPtrCommandeSquare_ptr;



class Joueur : public std::enable_shared_from_this<Joueur>{

    public :
        /*Etat dans lequel est le joueur lorsqu'il vaut utilser la case selectionnee*/
        enum EtatSelectedCase {NORMAL, DEPLACER_UNITE, ATTAQUER};



    private :
        const static int BOIS_DEPART = 10000;
        const static int NOURRITURE_DEPART = 10000;
        const static int OR_DEPART = 10000;

        bool enVie;

        std::string nom;
        
        // permet de definir a quoi sert la case selectionne
        EtatSelectedCase etatSelectCase;
        
        // ElementJoueur* selectedElement;
        std::set<ElementJoueur*> elementsAuJoueur;

        // renvoie les commandes quand une case est selectionne
        // depend de EtatSelectedCase
        // cree les commandes avec new, devront etre supprimees dans Dashboard::pushCommandeSquare()
        // renvoie nullptr si il n'y a pas de commandes a faire
        ListPtrCommandeSquare_ptr CommandesWhenSelectCase(Case_ptr &case_);


        CasePosition caseDepart;

        Case_ptr selectedCase;

        int _bois;
        int _nourriture;
        int _or;

        sf::Color couleur;



    public :
        /*

        caseDepart : premiere case dont le joueur est proprietaire
        */
        Joueur(std::string nom, sf::Color couleur, CasePosition caseDepart);
        Joueur(const Joueur &autre)=delete;
        Joueur &operator=(const Joueur &autre)=delete;

        // a faire au lancement de la partie
        // rend le joueur proprietaire de sa case de depart
        void setForPartie();


        // ElementJoueur* getSelectedElement() {
        //     return selectedElement;
        // }

        // appele par UserInterface::selectCase()

        // /!\ appele UNIQUEMENT par ElementJoueur::ElementJoueur
        void _addElement(ElementJoueur* element);

        // /!\ appele UNIQUEMENT par ElementJoueur::~ElementJoueur()
        void _removeElement(ElementJoueur* element);

        void whenSelectCase(Case_ptr &case_);

        // charge les commandes pour la case selectionne
        void loadSelectedCase();

        void whenDeselectCase();

        void changeEtatSelectedCase(EtatSelectedCase etat) {etatSelectCase=etat;};

        int getBois() const {return _bois;}

        int getNourriture() const {return _nourriture;}

        int getOr() const { return _or;}

        // renvoie si possible enlever bois
        bool peutDecreaseBois(int bois);

        // renvoie si possible enlever nourriture
        bool peutDecreaseNourriture(int nourriture);

        // renvoie si possible enlever or
        bool peutDecreaseOr(int _or);

        // enleve bois si possible (>0)
        // renvoie si possible
        // met a jour les infos du HUD
        bool decreaseBois(int bois);

        // enleve nourriture si possible (>0)
        // renvoie si possible
        // met a jour les infos du HUD
        bool decreaseNourriture(int nourriture);

        // enleve or si possible (>0)
        // renvoie si possible
        // met a jour les infos du HUD
        bool decreaseOr(int _or);

        sf::Color getCouleur() {return couleur;}


        std::string getName() {return nom;}

        CasePosition getCaseDepart() {return caseDepart;}

        void increaseRessource(int bois, int nourriture, int or_);



        // appele au debut du tour d'un joueur
        // active nouveau tour sur tous ses elements
        void nouveauTour();

        // detruit tous les entités appartenant au joueur avec delete, ne pas les utiliser apres !
        // met enVie=false
        // a activer lorsque le joueur a perdu ou lorsque la partie est termine
        void finDuJoueur();

        bool getEnVie() {return enVie;}




};

typedef std::shared_ptr<Joueur> Joueur_ptr;





#endif