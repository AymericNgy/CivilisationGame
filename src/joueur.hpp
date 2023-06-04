#ifndef JOUEUR
#define JOUEUR

#include "AffichableOnMap/element_joueur.hpp"
#include <set>
#include <memory>


typedef std::shared_ptr<Joueur> Joueur_ptr;
typedef std::shared_ptr<std::list<CommandeSquare*>> ListPtrCommandeSquare_ptr;


/**
 * \class Joueur
 * \brief Joueur de la partie
*/
class Joueur : public std::enable_shared_from_this<Joueur>{

    public :
        /**
         * \enum EtatSelectedCase
         * \brief Etat dans lequel est le joueur lorsqu'il vaut utilser la case selectionnee
        */
        enum EtatSelectedCase {NORMAL, DEPLACER_UNITE, ATTAQUER};



    private :
        // ---ATTRIBUTS---




        bool enVie;


        std::string nom;
        

        /**
         * \brief permet de definir a quoi sert la case selectionne
        */
        EtatSelectedCase etatSelectCase;
        

        /**
         * \brief liste des elements du joueur,
         * s'ajoute automatiquement quand un element est cree
         * se retire automatiquement quand un element est detruit
        */
        std::set<ElementJoueur*> elementsAuJoueur;

        CasePosition caseDepart;

        Case_ptr selectedCase;

        int _bois;
        int _nourriture;
        int _or;

        sf::Color couleur;

        // ---METHODES---

        /**
        * \brief renvoie les commandes quand une case est selectionne,
        * depend de EtatSelectedCase,
        * cree les commandes avec new, devront etre supprimees dans Dashboard::pushCommandeSquare(),
        * renvoie nullptr si il n'y a pas de commandes a faire.
        * \param case_ : case selectionnee
        */
        ListPtrCommandeSquare_ptr CommandesWhenSelectCase(Case_ptr &case_);

        




    public :

        // ---CONSTRUCTEURS---
        /*

        caseDepart : premiere case dont le joueur est proprietaire
        */
        Joueur(std::string nom, sf::Color couleur, CasePosition caseDepart);
        Joueur(const Joueur &autre)=delete;
        Joueur &operator=(const Joueur &autre)=delete;

        // --- CONSTANTES ---

        // ressources de depart
        const static int BOIS_DEPART = 1000;
        const static int NOURRITURE_DEPART = 800;
        const static int OR_DEPART = 100;

        // ---METHODES---

        /**
         * a faire au lancement de la partie,
         * rend le joueur proprietaire de sa case de depart
         * construit l'hotel de ville
        */
        void setForPartie();




        /**
         * \brief ajoute un element au joueur,
         * /!\ appele UNIQUEMENT pour le constructeur de ElementJoueur
         * \param element : element a ajouter
         * 
         * \sa ElementJoueur::ElementJoueur
        */
        void _addElement(ElementJoueur* element);

    
        /**
         * \brief retire un element au joueur,
         * /!\ appele UNIQUEMENT par le destructeur ElementJoueur::~ElementJoueur()
         * \param element : element a retirer
         * 
         * \sa ElementJoueur::~ElementJoueur
        */
        void _removeElement(ElementJoueur* element);

        /**
         * \brief active ce que fait le joueur quand il selectionne une case
         * \param case_ : case selectionnee
        */
        void whenSelectCase(Case_ptr &case_);


        /**
         *  \brief charge les commandes pour la case selectionne
        */
        void loadSelectedCase();

        /**
         * \brief met le joueur en mode normal (etatSelectCase=NORMAL) et netoie le dashboard
        */
        void whenDeselectCase();

        /**
         * \brief change l'etat d'utilisation de la case selectionnee
         * \param etat : nouvel etat
        */
        void changeEtatSelectedCase(EtatSelectedCase etat) {etatSelectCase=etat;};

        /**
         * \brief renvoie le nombre de bois du joueur
        */
        int getBois() const {return _bois;}

        /**
         * \brief renvoie le nombre de nourriture du joueur
        */
        int getNourriture() const {return _nourriture;}

        /**
         * \brief renvoie le nombre d'or du joueur
        */
        int getOr() const { return _or;}


        /**
         * \brief renvoie si possible d'enlever une quantite de bois
         * \param bois : quantite de bois a enlever
        */ 
        bool peutDecreaseBois(int bois);

        /**
         * \brief renvoie si possible d'enlever une quantite de nourriture
         * \param nourriture : quantite de nourriture a enlever
        */
        bool peutDecreaseNourriture(int nourriture);


        /**
         * \brief renvoie si possible d'enlever une quantite d'or
         * \param or_ : quantite d'or a enlever
        */
        bool peutDecreaseOr(int _or);


        /**
         * \brief enleve bois si possible (>0),
         * renvoie si possible,
         * met a jour les infos du HUD
         * \param bois : quantite de bois a enlever
         * \return si possible d'enlever la quantite de bois
        */
        bool decreaseBois(int bois);


        /**
         * \brief enleve nourriture si possible (>0),
         * renvoie si possible,
         * met a jour les infos du HUD
         * \param nourriture : quantite de nourriture a enlever
         * \return si possible d'enlever la quantite de nourriture
        */
        bool decreaseNourriture(int nourriture);


        /**
         * \brief enleve or si possible (>0),
         * renvoie si possible,
         * met a jour les infos du HUD
         * \param or_ : quantite d'or a enlever
         * \return si possible d'enlever la quantite d'or
        */
        bool decreaseOr(int _or);

        /**
         * \brief renvoie la couleur du joueur
        */
        sf::Color getCouleur() {return couleur;}

        /**
         * \brief renvoie le nom du joueur
        */
        std::string getName() {return nom;}

        /**
         * \brief renvoie la case de depart du joueur
        */
        CasePosition getCaseDepart() {return caseDepart;}

        /**
         * \brief augmente les ressources du joueur
         * \param bois : quantite de bois a ajouter
         * \param nourriture : quantite de nourriture a ajouter
         * \param or_ : quantite d'or a ajouter
        */
        void increaseRessource(int bois, int nourriture, int or_);



        /**
         * \brief a appeler au debut du tour d'un joueur
         * active nouveau tour sur tous ses elements
        */
        void nouveauTour();


        /**
         * \brief detruit tous les entités appartenant au joueur avec delete, ne pas les utiliser apres !\n
         * met enVie=false \n
         * a activer lorsque le joueur a perdu ou lorsque la partie est termine \n
        */
        void finDuJoueur();

        /**
         * \brief renvoie si le joueur est en vie
        */
        bool getEnVie() {return enVie;}




};

typedef std::shared_ptr<Joueur> Joueur_ptr;





#endif