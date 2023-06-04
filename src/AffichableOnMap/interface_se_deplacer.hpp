#ifndef INTERFACE_SE_DEPLACER
#define INTERFACE_SE_DEPLACER

class CasePosition;
class ElementJoueur;




/**
 * \class InterfaceSeDeplacer
 * \brief A implementer sur un ElementJoueur si il peut se deplacer \n
 * Ajouter commande ChoixSeDeplacer a la liste renvoye par ElementJoueur::getActionpossible()
*/
class InterfaceSeDeplacer {
    public :

        /**
         * \brief /!\ redefinir dans classe enfant avec bonus si voulu \n
        */
        virtual float getNombreCaseDeplacement() const =0;




        // renvoie l'instance ElementJoueur sur laquelle cette interface a ete implemente
        ElementJoueur *thisElementJoueur();
        



        void _commandeSeDeplacer();

        void _commandeChoixSeDeplacer();



        

    


};


#endif