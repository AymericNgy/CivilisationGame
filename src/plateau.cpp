#include "plateau.hpp"
#include "case.hpp"
#include "UserInterface/affichable_on_map.hpp"
#include "AffichableOnMap/terrain.hpp"
#include "joueur.hpp"
#include <iostream>
#include "utile.hpp"
#include "AffichableOnMap/marque.hpp"
#include "jeu.hpp"
#include "plateau.hpp"
#include "AffichableOnMap/element_joueur.hpp"



void Plateau::constructGrille(int taille_x, int taille_y) {
    this->taille_x=taille_x;
    this->taille_y=taille_y;
    

    
    for (int i = 0; i < taille_x; i++)
    {
        for (int j = 0; j < taille_y; j++)
        {
            
            CasePosition casePosition(i,j);


            Case_ptr case_ = std::make_shared<Case>(casePosition,*this);
            
            cases.insert(std::pair<CasePosition, Case_ptr>(casePosition,case_ ));

            //c'est plateau qui doit gerer la creation de terrain car la case (le jeu?) doit deja etre cree pour pouvoir cree un AffichableOnMap
            Terrain *terrain = new Terrain(*this,casePosition);
            terrains.insert(terrain);

            cases.at(casePosition)->addElementOn(terrain); 

        }     
    }
}


void Plateau::destructGrille() {
    for (const auto& terrain : terrains) {
        delete terrain;
    }
    for (const auto& case_ : cases) {
        case_.second->setProprietaire(nullptr);
    }
}



Plateau::Plateau(int taille_x, int taille_y) {

    this->constructGrille(taille_x, taille_y);

    drawMarqueProprietaire();
}


Plateau::~Plateau() {
    this->destructGrille();
}

void Plateau::moveElement(CasePosition positionDepart, CasePosition positionArrive, AffichableOnMap *element) {
    if (!inPlateau(positionDepart) || !inPlateau(positionArrive)) {
        throw std::runtime_error("Plateau::moveElement() -> case en dehors du plateau");
    }

    Case_ptr caseDepart = cases.at(positionDepart);
    Case_ptr caseArrivee = cases.at(positionArrive);
    
    caseDepart->removeElementOn(element);
    caseArrivee->addElementOn(element);

}

void Plateau::addElement(CasePosition position, AffichableOnMap *element) {

    if (!inPlateau(position)) {
        throw std::runtime_error("Plateau::addElement() -> case en dehors du plateau");
    }
    Case_ptr case_= cases.at(position);

    case_->addElementOn(element);
}

void Plateau::removeElement(CasePosition position, AffichableOnMap *element) {
    if (!inPlateau(position)) {
        throw std::runtime_error("Plateau::removeElement() -> case en dehors du plateau");
    }
    Case_ptr case_= cases.at(position);
    case_->removeElementOn(element);
}

bool Plateau::inPlateau(CasePosition cp) const {
    return 0<=cp.x && cp.x<taille_x && 0<=cp.y && cp.y<taille_y;
}


Case_ptr Plateau::getCaseAt(CasePosition cp){
    if (!inPlateau(cp)) {
        Utile::erreur("Plateau::getCaseAt()","case en dehors du plateau");
    }
    return cases.at(cp);
}

Case_ptr Plateau::getCaseAt(CasePosition cp) const{
    if (!inPlateau(cp)) {
        Utile::erreur("Plateau::getCaseAt()","case en dehors du plateau");
    }
    return cases.at(cp);
}

int Plateau::nombreElementCase(CasePosition cp) const {
    return this->getCaseAt(cp)->nbElement();
}

std::ostream& operator<<(std::ostream& os, const Plateau &plateau) {
    for (int i = 0; i < plateau.getTaille_x(); i++)
    {
        for (int j = 0; j < plateau.getTaille_y(); j++)
        {
            os << "{"<<i<<","<<j<<"} nombre element : " << plateau.nombreElementCase(CasePosition(i,j))<<"    ";
        }
        os << std::endl;
    }
        
    return os;
}


// Case_ptr &Plateau::getCase(CasePosition position) {
//     if (!inPlateau(position)) {
//         Utile::erreur("Plateau::getCaseAt()","case en dehors du plateau");
//     }
//     return cases.at(position);
// }


float Plateau::distance(CasePosition position_1, CasePosition position_2) {
    float distance_x=0, distance_y=0;



    distance_y = (float)(position_2.y-position_1.y)/2;

    if ((position_2.y-position_1.y)%2==0) {
        distance_x=(position_2.x-position_1.x)*2;
    }
    else {
        if (position_1.y%2==0) {
            distance_x=(position_2.x-position_1.x+0.5)*2;
        } else {
            distance_x=(position_2.x-position_1.x-0.5)*2;
        }
    }

    return sqrt(distance_x*distance_x+distance_y*distance_y)+0.0001; // /!\ ajout 0.0001 utile car parfois on est a la limite des cases
}


void Plateau::setCaseProprietaire(CasePosition casePosition, Joueur_ptr proprietaire) {

    Case_ptr case_ = getCaseAt(casePosition);
    case_->setProprietaire(proprietaire);
}


void Plateau::updateMarqueProprietaire() {
    if (afficherMarquesProprietaires) {
        drawMarqueProprietaire();
    }
}

void Plateau::drawMarqueProprietaire() {
    eraseMarqueProprietaire();
    afficherMarquesProprietaires=true;
    for (const auto& case_ : cases) {

        if(case_.second->getProprietaire()!=nullptr) {
            marquesProprietaire.insert(new Marque(case_.second->getProprietaire(),*this,case_.first));
        }
    }

}

void Plateau::eraseMarqueProprietaire() {
    afficherMarquesProprietaires=false;
    for (const auto& marqueProprietaire : marquesProprietaire) {
        delete marqueProprietaire;
    }
    marquesProprietaire.clear();
}





bool Plateau::appartientDansAdjacence(Joueur_ptr joueur,CasePosition case_) {
    if (getCaseAt(case_)->getProprietaire()==joueur) {
        return false;
    }
    float rayon = 1.5;
    CasePosition point(0,0);
    for (int x=case_.x-rayon*2; x<case_.x+rayon*2; x++) {
        for (int y = case_.y-rayon*2; y < case_.y+rayon*2; y++)
        {

            point.x =x; point.y=y;
            if (Jeu::getInstance().getPlateau().inPlateau(point) && Plateau::distance(point,case_)<=rayon) {  //les cases adjacentes
                if (getCaseAt(point)->getProprietaire()==joueur) {
                    return true;
                }

            }

            

        }
        
    }
    return false;
}



ElementJoueur *Plateau::ennemiSurCase(Joueur_ptr joueur, CasePosition position) {
    Case_ptr case_ = getCaseAt(position);
    std::set<AffichableOnMap *> &affichablesOnCase  = case_->getElementsOn();
    int pvMax=-1;
    ElementJoueur *elementAvecPlusPv=nullptr;
    
    ElementJoueur *currentElementJoueur;
    for (auto affichable = affichablesOnCase.begin();affichable != affichablesOnCase.end(); affichable++) {
        currentElementJoueur = dynamic_cast<ElementJoueur*>(*affichable);
        if (currentElementJoueur) { //teste si c'est bien un ElementJoueur
            if (currentElementJoueur->getJoueurProprietaire() != joueur) {
                if (currentElementJoueur->getPv()>pvMax) {
                    pvMax=currentElementJoueur->getPv();
                    elementAvecPlusPv=currentElementJoueur;
                }
            }
        }
        
    }

    return elementAvecPlusPv;
}