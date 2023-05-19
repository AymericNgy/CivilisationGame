#ifndef INTERFACE_ATTAQUER
#define INTERFACE_ATTAQUER




class ElementJoueur;

// A implementer sur un ElementJoueur si il peut attaquer
class InterfaceAttaquer {
    public :
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