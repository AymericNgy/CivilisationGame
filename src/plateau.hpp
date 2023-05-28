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





// permet d'avoir des INFOS sur les elements presents sur le plateau
// deplacement sur plateau gere par les affichableOnMap
class Plateau {
    private :
        std::map<CasePosition,Case_ptr> cases;
        std::set<Terrain*> terrains;

        int taille_x;
        int taille_y;


        bool afficherMarquesProprietaires;

        // permet d'afficher sur le plateau qui est proprietaire de chaque case
        std::set<Marque*> marquesProprietaire;


        // creee les cases de la map
        // cree les terrains dessus
        void constructGrille(int taille_x, int taille_y);

        // detruit les terrains sur le plateau
        void destructGrille();



        Case_ptr getCaseAt(CasePosition cp) const;

    public :

        

        Plateau(int taille_x, int taille_y);

        // detruit les terrains sur le plateau
        ~Plateau();

        bool inPlateau(CasePosition cp) const;

        int nombreElementCase(CasePosition cp) const; 



        // /!\ DOIT ETRE UTILISE UNIQUEMENT PAR AffichableOnMap /!\  .
        void moveElement(CasePosition positionDepart, CasePosition positionArrive, AffichableOnMap *element);

        // /!\ DOIT ETRE UTILISE UNIQUEMENT PAR AffichableOnMap /!\  .
        void addElement(CasePosition position, AffichableOnMap *element);

        // /!\ DOIT ETRE UTILISE UNIQUEMENT PAR AffichableOnMap /!\  .
        void removeElement(CasePosition position, AffichableOnMap *element);



        int getTaille_x() const {return taille_x;}

        int getTaille_y() const {return taille_y;}

        Case_ptr getCaseAt(CasePosition position);

        // distance entre la case position_1 et position_2
        // renvoie +0.0001 si position_1=position_2
        float static distance(CasePosition position_1, CasePosition position_2);
        
        void setCaseProprietaire(CasePosition casePosition, Joueur_ptr proprietaire);

        // affiche marque proprietiare (mise a jour) si plateau est dans mode afficher marques
        void updateMarqueProprietaire();

        // affiche marque proprietiare (mise a jour)
        void drawMarqueProprietaire();

        void eraseMarqueProprietaire();

        // renvoie si le joueur a une case qui lui appartient les cases adjacentes au parametre case_
        // renvoie faux si la case appartient au joueur
        bool appartientDansAdjacence(Joueur_ptr joueur,CasePosition case_);

        // renvoie l'ennemi sur la case a la position 'position' qui a le plus de vie
        // renvoie nullptr s'il n'y a pas d'ennemi sur la case
        ElementJoueur *ennemiSurCase(Joueur_ptr joueur, CasePosition position);



};


std::ostream& operator<<(std::ostream& os, const Plateau &plateau);




#endif