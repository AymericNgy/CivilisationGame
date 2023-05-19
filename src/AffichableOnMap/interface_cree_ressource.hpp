#ifndef INTERFACE_CREE_RESSOURCE
#define INTERFACE_CREE_RESSOURCE

// A implementer sur un ElementJoueur si il cree des ressources a chaque tour
// Ajouter ... [!]
class InterfaceCreeRessource {

    public :
        // nombre de ressource cree par tour
        // /!\ redefinir dans classe enfant avec bonus si voulu
        virtual void ressourceParTour(int &bois, int &nourriture, int &_or) = 0;

        // [!] ... IMPLEMENTER
        void creationRessourceTour();


};








#endif
