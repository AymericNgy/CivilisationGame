#ifndef INTERFACE_ATTAQUER
#define INTERFACE_ATTAQUER




class ElementJoueur;


/**
 * \class InterfaceAttaquer
 * \brief A implementer sur un ElementJoueur si il peut attaquer \n
 * Ajouter commande ChoixAttaquer a la liste renvoye par ElementJoueur::getActionpossible()
*/
class InterfaceAttaquer {
    


    public :
        // renvoie le coeffecient multiplicatif d'attaque de l'attaquant sur le recevant
        // renvoie 1 s'il n'y en a pas
        static float coeffAttaque(InterfaceAttaquer *attaquant, ElementJoueur *recevant);
    
        // /!\ redefinir dans classe enfant avec bonus si voulu
        virtual float getNombreDegat() const =0;    

        // /!\ redefinir dans classe enfant avec bonus si voulu
        virtual float getDistanceAttaque() const =0;  

        // renvoie l'instance ElementJoueur sur laquelle cette interface a ete implemente
        ElementJoueur *thisElementJoueur();

        void _commandeAttaquer();

        void _commandeChoixAttaquer();

};



















#endif