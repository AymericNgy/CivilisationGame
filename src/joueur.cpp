#include "joueur.hpp"
#include "utile.hpp"
#include "jeu.hpp"
#include "hud.hpp"
#include "Commande/select_element.hpp"
#include "Commande/acheter_case.hpp"
#include "Commande/choix_construire.hpp"
#include "hud.hpp"
#include "AffichableOnMap/hotel_de_ville.hpp"


Joueur::Joueur(std::string nom, sf::Color couleur,CasePosition caseDepart) : caseDepart(caseDepart), nom(nom), couleur(couleur){
    etatSelectCase=NORMAL;
    _bois = BOIS_DEPART;
    _nourriture = NOURRITURE_DEPART;
    _or = OR_DEPART;
    selectedCase=nullptr;

    enVie = true;


    int bois_= getBois();
    int nourriture_ = getNourriture();
    int or_= getOr();
    
}


void Joueur::setForPartie() {
    Jeu::getInstance().getPlateau().setCaseProprietaire(caseDepart,shared_from_this());
    // construction des hotels de ville 
    HotelDeVille *hdv = new HotelDeVille(shared_from_this());
    hdv->moveToPosition(caseDepart);
    hdv->init(true);

}

void Joueur::loadSelectedCase() {
    ListPtrCommandeSquare_ptr commandes = CommandesWhenSelectCase(selectedCase);
    if (commandes) {
        Jeu::getInstance().getHud().pushCommandes(commandes,"choississez une action a effectuer sur la case.");
    }
}

void Joueur::whenSelectCase(Case_ptr &case_) {
    selectedCase=case_;
    loadSelectedCase();

}


ListPtrCommandeSquare_ptr Joueur::CommandesWhenSelectCase(Case_ptr &case_) {

    
    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();


    
    switch (etatSelectCase)
    {
    case NORMAL: {
        // booleen a vrai si la commande est disponible :
        bool commandeSelectElement = (case_->nombreElementJoueurOn(shared_from_this())!=0);
        bool commandeAcheterCase = (Jeu::getInstance().getPlateau().appartientDansAdjacence(shared_from_this(),case_->getPosition())&& case_->getProprietaire()==nullptr);
        bool commandeChoixConstuire = (!case_->batimentsOn() && case_->getProprietaire()==shared_from_this());

        
        // on pâsse en revue les cas ou s'il il n'a qu'une commande selectElement ou ChoixConstuire on peut les executer
        if (commandeSelectElement && !commandeAcheterCase && !commandeChoixConstuire) {
            SelectElement selectElement(case_);
            selectElement.execute();
            return nullptr;
        } else if (!commandeSelectElement && !commandeAcheterCase && commandeChoixConstuire) {
            ChoixConstuire choixConstuire(case_);
            choixConstuire.execute();
            return nullptr;
        } else {  
            
            

            if (commandeSelectElement) {
                commandes->push_back(new SelectElement(case_));
            }
            if (commandeAcheterCase) {
                commandes->push_back(new AcheterCase(case_));
            }
            if (commandeChoixConstuire) {
                commandes->push_back(new ChoixConstuire(case_));
            }
            return commandes;

        }


        break;
    }
    case DEPLACER_UNITE:
        return nullptr;

    case ATTAQUER:
        return nullptr;

    default:
        break;
    }
}

void Joueur::whenDeselectCase() {
    selectedCase = nullptr;
    etatSelectCase = NORMAL;

    Jeu::getInstance().getHud().clearAll();
}





void Joueur::_addElement(ElementJoueur* element) {
    elementsAuJoueur.insert(element);
}


void Joueur::_removeElement(ElementJoueur* element){
    if(elementsAuJoueur.erase(element)!=1) {
        Utile::warning("Joueur::_removeElement","le nombre d'element enleve n'est pas de 1");
    }
}


bool Joueur::decreaseBois(int bois) {
    if (this->_bois-bois>=0) {
        this->_bois-=bois;
        Jeu::getInstance().getHud().updateRessources();
        return true;
    }
    else {
        return false;
    }
}


bool Joueur::decreaseNourriture(int nourriture) {
    if (this->_nourriture-nourriture>=0) {
        this->_nourriture-=nourriture;
        Jeu::getInstance().getHud().updateRessources();
        return true;
    }
    else {
        return false;
    }
}


bool Joueur::decreaseOr(int _or) {
    if (this->_or-_or>=0) {
        this->_or-=_or;
        Jeu::getInstance().getHud().updateRessources();
        return true;
    }
    else {
        return false;
    }
}


bool Joueur::peutDecreaseBois(int bois) {
    return this->_bois-bois>=0;
}


bool Joueur::peutDecreaseNourriture(int nourriture) {
    return this->_nourriture-nourriture>=0;
}


bool Joueur::peutDecreaseOr(int _or) {
    return this->_or-_or>=0;
}

void Joueur::nouveauTour() {
    etatSelectCase=NORMAL;
    selectedCase = nullptr;
    for (auto it = elementsAuJoueur.begin(); it!=elementsAuJoueur.end();it++) {
        (*it)->nouveauTour();
    }   
}



void Joueur::increaseRessource(int bois, int nourriture, int or_) {
    this->_bois += bois;
    this->_nourriture += nourriture;
    this->_or += or_;
}

void Joueur::finDuJoueur() {
    selectedCase=nullptr;
    enVie=false;
    std::vector<ElementJoueur*> listeElement;
    for (auto element = elementsAuJoueur.begin(); element != elementsAuJoueur.end() ; element++)
    {
        listeElement.push_back(*element);
    }
    for (size_t i = 0; i < listeElement.size(); i++)
    {
        delete listeElement[i];
    }
    


    Jeu::getInstance().decreaseNombreJoueurEnvie();
    
}