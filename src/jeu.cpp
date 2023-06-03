#include "jeu.hpp"
#include "plateau.hpp"
#include "joueur.hpp"
#include "case.hpp"
#include "UserInterface/SpriteForUI.hpp"
#include "UserInterface/affichable_on_map.hpp"
#include "AffichableOnPanel/dashboard.hpp"
#include "UserInterface/text_for_ui.hpp"
#include "AffichableOnMap/caserne.hpp"
#include "utile.hpp"
#include "AffichableOnMap/fantassin.hpp"
#include "hud.hpp"
#include "info_commande.hpp"
#include "AffichableOnMap/marque.hpp"
#include "AffichableOnMap/mine.hpp"
#include "AffichableOnPanel/menu.hpp"

using namespace std;


Jeu::Jeu()  {
    menu=new Menu();
    plateau = nullptr;

    hud = nullptr;

    indiceJoueurActif=-1;

    etatPartie = MENU;
    





    
}


Jeu* Jeu::m_instance = nullptr;

Jeu& Jeu::getInstance() {



    if (Jeu::m_instance ==nullptr) {
        std::cout<<"nouveau jeu"<< std::endl;
        Jeu::m_instance = new Jeu();

    }

    return *Jeu::m_instance;
}


void Jeu::commencer() {
    cout<<"Le jeu commence"<<endl;

    UserInterface &userInterface = UserInterface::getInstance();



    






    userInterface.runMainLoop();
}

Joueur_ptr &Jeu::getJoueurActif() {
    if (indiceJoueurActif==-1) {
        Utile::erreur(__func__,"aucun joueur encore cree");
    }

    if (indiceJoueurActif>=joueurs.size()) {
        Utile::erreur(__func__,"indice du joueur invalide");
    }
    return joueurs[indiceJoueurActif];
}


void Jeu::changerJoueur() {
    if (nombreJoueurEnVie==1) {
        arretPartie();
    } else {
        do {
            indiceJoueurActif+=1;
            indiceJoueurActif%=NOMBRE_JOUEUR;
        } while (!joueurs[indiceJoueurActif]->getEnVie());

        updateNouveauTour();
    }






}


// void Jeu::lancerPartie(std::vector<Joueur_ptr> &joueurs) {
//     plateau = new Plateau(Jeu::TAILLE_PLATEAU_X,Jeu::TAILLE_PLATEAU_Y);


//     for (int i=0; i< NOMBRE_JOUEUR;i++) {
//         joueurs[i]->setForPartie();
//     }

//     plateau->drawMarqueProprietaire();

//     for (int i=0; i<joueurs.size();i++) {
                
//         this->joueurs.push_back(joueurs[i]);
//     }

//     indiceJoueurActif = 0;
//     nombreJoueurEnVie=NOMBRE_JOUEUR;
//     hud = new Hud();

//     updateNouveauTour();

//     std::cout <<"nombreJoueurEnVie " <<nombreJoueurEnVie << std::endl;


// }


void Jeu::finPartie() {
    delete plateau;
    plateau = nullptr;
    delete hud;
    hud=nullptr;
    

    joueurs.clear();
    indiceJoueurActif=-1;
}

Plateau& Jeu::getPlateau() {
    if (plateau==nullptr) {
        Utile::erreur(__func__,"acces impossible au plateau qui n'existe pas");
    }
    return *plateau;}

Hud& Jeu::getHud() {
    if (hud==nullptr) {
        Utile::erreur(__func__,"acces impossible au HUD qui n'existe pas");
    }
    return *hud;
}

void Jeu::updateNouveauTour() {
    getJoueurActif()->nouveauTour();
    hud->changeJoueur();
    
    UserInterface &ui = UserInterface::getInstance();
    ui.nouveauTour();
}


void Jeu::lancerPartie() {
    std::vector<Joueur_ptr> NouveauJoueurs;


    nombreJoueurEnVie=NOMBRE_JOUEUR;
    
  
    NouveauJoueurs.push_back(make_shared<Joueur>("Aymeric",sf::Color::Blue,CasePosition(10,10)));
    NouveauJoueurs.push_back(make_shared<Joueur>("Titouan",sf::Color::Red,CasePosition(15,10)));
    NouveauJoueurs.push_back(make_shared<Joueur>("Lou",sf::Color::Green,CasePosition(10,20)));
    NouveauJoueurs.push_back(make_shared<Joueur>("Natt",sf::Color::Magenta,CasePosition(15,20)));



    plateau = new Plateau(Jeu::TAILLE_PLATEAU_X,Jeu::TAILLE_PLATEAU_Y);


    for (int i=0; i< NOMBRE_JOUEUR;i++) {
        NouveauJoueurs[i]->setForPartie();
    }

    plateau->drawMarqueProprietaire();



    for (int i=0; i<NouveauJoueurs.size();i++) {
                
        this->joueurs.push_back(NouveauJoueurs[i]);
    }

    indiceJoueurActif = 0;
    hud = new Hud();

    updateNouveauTour();

    UserInterface::getInstance().initUIForPartie();

    etatPartie=EN_PARTIE;


    delete menu;
    menu = nullptr;
}

void Jeu::arretPartie() {
    getJoueurActif()->finDuJoueur(); 
    etatPartie=MENU;
    menu=new Menu();
    UserInterface::getInstance().finishUIForEndPartie();
    delete hud;
    hud =nullptr;
    delete plateau;
    plateau= nullptr;
    this->joueurs.clear();

    
}