#ifndef ELEMENT_JOUEUR
#define ELEMENT_JOUEUR

#include <memory>
#include "../UserInterface/affichable_on_map.hpp"
#include <iostream>
#include <list>
#include "../Commande/commande_square.hpp" 

typedef std::shared_ptr<Joueur> Joueur_ptr;


// Classe abstraite correspondant a tous les elements pouvant appartenir a un joueur
// S'ajoute a sa creation au joueurProprietaire
// se retire a sa destruction du joueurProprietaire
class ElementJoueur : public AffichableOnMap{



    protected :

        std::string info;
        std::string name;
        std::string iconTextureFileName;

        Joueur_ptr joueurProprietaire;

        int nombreActionRestante;

        int pv;
        






        // renvoie si nombreActionRestante > 0
        bool peutDecrementeAction() {return nombreActionRestante>0;}

        // renvoie si l'element peut etre achete (cree) par le joueur actif
        // /!\ a utiliser comme une methode statique abstraite
        virtual bool peutEtreAchete();

        void resetNombreAction();


    public :

        // decremente le nombre d'action si possible (si >0)
        // renvoie si il reste encore des actions (si >0)
        // met a jour les infos de l'element selectionne
        bool decreaseNombreAction();

        // pv et NombreActionRestante a 0
        ElementJoueur(int couche,std::string textureFileName,std::string info,std::string name,std::string iconTextureFileName,Joueur_ptr joueurProprietaire);
        
        ~ElementJoueur();

        // met nombrePv a PvMax
        // met nombreAction a nombreActionMax si initNombreAction=true
        void init(bool initNombreAction);
        
        // /!\ renvoie des commandes avec new, elles sont destinées au dashboard
        // /!\ ne pas les utiliser pour autre chose que le dashboard car elles seront supprimees par celui ci
        virtual ListPtrCommandeSquare_ptr getActionPossible() =0;

        // /!\ redefinir dans classe enfant avec bonus si voulu
        virtual int getNombreActionMax() const =0;

        // /!\ redefinir dans classe enfant avec bonus si voulu
        virtual int getPvMax() const =0;

        // appele par Construire<T>::execute() quand c'est un element (this) qui cree l'element
        // construction de l'instance est faite dans void Construire<T>::execute()
        // rajoute les autres traitements a faire avant ici :
        // - teste et decrease nombre action
        // - teste et decrease ressources
        // renvoie si la commande peut etre faite
        // instanceTypeACreer -> l'instance pour connaitre quel type il faut creer
        bool _commandeCreerElement(ElementJoueur &instanceTypeACreer);

        // appele par Construire<T>::execute() quand il n'ya pas d'element constructeur
        // construction de l'instance est faite dans void Construire<T>::execute()
        // rajoute les autres traitements a faire avant ici :
        // - teste et decrease ressources
        // renvoie si la commande peut etre faite
        // instanceTypeACreer -> e l'instance pour connaitre quel type il faut creer
        static bool _staticCommandeCreerElement(ElementJoueur &instanceTypeACreer);

        int getNombreActionRestante() {return nombreActionRestante;}

        int getPv() const {return pv;}

        std::string getInfo() const {return info;}

        std::string getName() const {return name;}

        std::string getIconTextureFileName() const {return iconTextureFileName;}
        
        // rempli les arguments avec nombre de ressource pour achat de cette element
        // /!\ a utiliser comme une methode statique abstraite
        virtual void ressourcePourAchat(int &bois, int &nourriture, int &_or) = 0;

        // active lorsqu'il y a un nouveau tour 
        // remet entre autre le nombre d'action au max
        virtual void nouveauTour()=0;

        // renvoie le joueur proprietaire
        Joueur_ptr getJoueurProprietaire() {return joueurProprietaire;}

        // retire pv au nombre de pv du joueur
        // si pv atteint 0 ou moins delete this
        // renvoie true si l'element est mort (0 pv)
        bool decreasePv(int pv);







};











//typedef std::shared_ptr<ElementJoueur> ElementJoueur_ptr;



#endif