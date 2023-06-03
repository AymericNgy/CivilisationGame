#ifndef PLATEAU
#define PLATEAU

#include <map>
#include <memory>
#include <iostream>
#include "case.hpp"

class Case;
typedef std::shared_ptr<Case> Case_ptr;
class AffichableOnMap;
class Marque;
class ElementJoueur;






/**
 * \class Plateau
 * \brief permet d'avoir des INFOS sur les elements presents sur le plateau\n
 * /!\ Deplacement sur plateau gere par les affichableOnMap : \n
 * Ce sont eux et seulement eux qui doivent appeler les methodes de deplacement de plateau
*/
class Plateau {
    private :
        // ---ATTRIBUTS---

        /**
         * \brief ensemble des cases du plateau
        */
        std::map<CasePosition,Case_ptr> cases;
        /**
         * \brief ensemble des terrains du plateau
        */
        std::set<Terrain*> terrains;

        // taille du plateau
        int taille_x;
        int taille_y;





        /**
         * \brief permet d'afficher sur le plateau qui est proprietaire de chaque case avec des marques
        */
        std::set<Marque*> marquesProprietaire;

        /**
         * \brief true si on affiche les marques de proprietaire
        */
        bool afficherMarquesProprietaires;


        /**
         * \brief cree les cases de la map \n
         * cree les terrains dessus
        */
        void constructGrille(int taille_x, int taille_y);


        /**
         * \brief detruit les terrains sur le plateau
        */
        void destructGrille();


        /**
         * \brief renvoie la case a la position 'cp' \n
         * message d'erreur si la case n'existe pas
         * \param cp position de la case
        */
        Case_ptr getCaseAt(CasePosition cp) const;

    public :

        
        // ---CONSTRUCTEURS---

        Plateau(int taille_x, int taille_y);


        /**
         * \brief detruit les terrains sur le plateau
        */
        ~Plateau();

        // ---METHODES---
        /**
         * \brief renvoie true si la case est dans le plateau
        */
        bool inPlateau(CasePosition cp) const;

        /**
         * \brief renvoie le nombre d'element sur la case 'cp'
         * \param cp position de la case
        */
        int nombreElementCase(CasePosition cp) const; 




        /**
         * \brief deplace l'element 'element' de la case 'positionDepart' a la case 'positionArrive'
         * /!\ DOIT ETRE UTILISE UNIQUEMENT PAR AffichableOnMap /!\  
        */
        void moveElement(CasePosition positionDepart, CasePosition positionArrive, AffichableOnMap *element);


        /**
         * \brief ajoute l'element 'element' a la case 'position'
         * /!\ DOIT ETRE UTILISE UNIQUEMENT PAR AffichableOnMap /!\
        */
        void addElement(CasePosition position, AffichableOnMap *element);


        /**
         * \brief retire l'element 'element' de la case 'position'
         * /!\ DOIT ETRE UTILISE UNIQUEMENT PAR AffichableOnMap /!\
        */
        void removeElement(CasePosition position, AffichableOnMap *element);


        /**
         * \brief renvoie la taille du plateau celon x
        */
        int getTaille_x() const {return taille_x;}

        /**
         * \brief renvoie la taille du plateau celon y
        */
        int getTaille_y() const {return taille_y;}

        /**
         * \brief renvoie la case a la position 'position' \n
         * message d'erreur si la case n'existe pas
         * \param position position de la case
        */
        Case_ptr getCaseAt(CasePosition position);



        /**
         * \brief renvoie la distance entre la case 'position_1' et la case 'position_2' \n
         * renvoie +0.0001 si position_1=position_2
         * \param position_1 position de la case 1
         * \param position_2 position de la case 2
        */
        float static distance(CasePosition position_1, CasePosition position_2);

        /**
         * \brief renvoie la distance entre la case 'position_1' et la case 'position_2' \n
        */
        void setCaseProprietaire(CasePosition casePosition, Joueur_ptr proprietaire);


        /**
         * \brief affiche marque proprietiare (mise a jour) si plateau est dans mode afficher marques
        */
        void updateMarqueProprietaire();


        /**
         * \brief affiche marque proprietiare (mise a jour)
        */
        void drawMarqueProprietaire();

        /**
         * \brief efface marque proprietiare (mise a jour)
        */
        void eraseMarqueProprietaire();


        /**
         * \brief renvoie si le joueur a une case qui lui appartient dans les cases adjacentes au parametre case_ \n
         * \param joueur joueur dont on veut savoir si il a une case qui lui appartient dans les cases adjacentes au parametre case_
         * \param case_ case au centre
         * \return true si le joueur a une case qui lui appartient dans les cases adjacentes au parametre case_,
         * renvoie faux si la case appartient au joueur
        */
        bool appartientDansAdjacence(Joueur_ptr joueur,CasePosition case_);


        /**
         * \brief renvoie l'ennemi sur la case a la position 'position' qui a le plus de vie \n
         * renvoie nullptr s'il n'y a pas d'ennemi sur la case
        */
        ElementJoueur *ennemiSurCase(Joueur_ptr joueur, CasePosition position);



};


std::ostream& operator<<(std::ostream& os, const Plateau &plateau);




#endif