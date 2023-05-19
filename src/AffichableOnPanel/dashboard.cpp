#include "dashboard.hpp"
#include "../Commande/commande_square.hpp"
#include "../AffichableOnMap/element_joueur.hpp"
#include "../utile.hpp"
#include "../AffichableOnMap/interface_se_deplacer.hpp"
#include "../AffichableOnMap/interface_attaquer.hpp"
#include "../AffichableOnMap/interface_cree_ressource.hpp"
#include "../AffichableOnMap/fantassin.hpp"
#include "../jeu.hpp"
#include <sstream>
#include <iomanip>
#include "../joueur.hpp"



const std::string Dashboard::TEXTURE_NAME = "dash_board_complete_2.png";


Dashboard::Dashboard() : AffichableOnPanel(Pixel(POSITION_X,POSITION_Y),Dashboard::COUCHE,TEXTURE_NAME) {
    initInfo();
    elementJoueurPourInfo=nullptr;
    updateInfoElement();
}

Dashboard::~Dashboard() {
    delete nom_element_info;
    delete icon_element_info;
    delete vie_element_info;
    delete tour_element_info;
    delete info_normal;
    delete nombre_case_deplacement;
    delete nombreDegat;
    delete distanceAttaque;
    delete creationRessource;

}

void Dashboard::pushCommandeSquare(ListPtrCommandeSquare_ptr commandes) {
               
    cleanCommandeSquare();



    int k =0;
    int x_case = 0;
    int y_case = 0;
    for (auto it = commandes->begin(); it != commandes->end(); it++)
    {
        x_case = k%NOMBRE_CASE_X;
        y_case = k/NOMBRE_CASE_X;


        (*it)->setPosition(ORIGINE_QUADRILLAGE_X+x_case*(TAILLE_CARRE+TAILLE_INTERSTICE),ORIGINE_QUADRILLAGE_Y+y_case*(TAILLE_CARRE+TAILLE_INTERSTICE));

        commandesSquare.push_back(*it);

        if (k>=NOMBRE_CASE_X*NOMBRE_CASE_Y) {
            Utile::warning("Dashboard::pushCommandeSquare","plus de commandes que de cases");
        }

        k++;


    }






}



void Dashboard::cleanCommandeSquare() {
    for (auto it = commandesSquare.begin(); it != commandesSquare.end(); it++)
    {
        delete (*it);
    }
    
    commandesSquare.clear();
}


void Dashboard::pushInfoElement(ElementJoueur *elementJoueurPourInfo) {
    removeInfoNormal();

    this->elementJoueurPourInfo=elementJoueurPourInfo;


    pushCommandeSquare(elementJoueurPourInfo->getActionPossible());
    updateInfoElement();
}


void Dashboard::updateInfoElement() {

    nom_element_info->setString("");
    icon_element_info->setTextures(UserInterface::TRANSPARENCY_TEXTURE_NAME);
    vie_element_info->setString("");
    tour_element_info->setString("");
    nombre_case_deplacement->setString("");
    nombreDegat->setString("");
    distanceAttaque->setString("");
    creationRessource->setString("");

    if (elementJoueurPourInfo!=nullptr) { // teste si un element est present dans le dashboard pour etre affiche
        nom_element_info->setString(elementJoueurPourInfo->getName()+" de [DEBUG] "+elementJoueurPourInfo->getJoueurProprietaire()->getName());
        icon_element_info->setTextures(elementJoueurPourInfo->getIconTextureFileName());
        vie_element_info->setString("Pv : " + std::to_string(elementJoueurPourInfo->getPv()) +"/"+ std::to_string(elementJoueurPourInfo->getPvMax()));
        tour_element_info->setString("Nombre Actions : "+ std::to_string(elementJoueurPourInfo->getNombreActionRestante())+"/"+ std::to_string(elementJoueurPourInfo->getNombreActionMax()));
    
        // teste si elementJoueurPourInfo est deplacable et affiche infos de deplacement si oui
        InterfaceSeDeplacer *elementDeplacable;
        elementDeplacable = dynamic_cast<InterfaceSeDeplacer*>(elementJoueurPourInfo);
        if (elementDeplacable) {
            std::stringstream deplacement;
            deplacement << std::fixed << std::setprecision(1) << elementDeplacable->getNombreCaseDeplacement();
            nombre_case_deplacement->setString("Distance de deplacement : "+ deplacement.str() +" cases");
        }

        // teste si elementJoueurPourInfo peut attaquer et affiche infos d'attaque si oui
        InterfaceAttaquer*elementAttaquant;
        elementAttaquant = dynamic_cast<InterfaceAttaquer*>(elementJoueurPourInfo);
        if (elementAttaquant) {
            std::stringstream nombreDegatString;
            nombreDegatString << elementAttaquant->getNombreDegat();
            nombreDegat->setString("Nombre de degats : "+ nombreDegatString.str() );

            std::stringstream distanceAttaqueString;
            distanceAttaqueString << std::fixed << std::setprecision(1) << elementAttaquant->getDistanceAttaque();
            distanceAttaque->setString("Distance d'attaque : "+ distanceAttaqueString.str() +" cases");

        }
        // teste si elementJoueurPourInfo peut creer des ressources affiche infos de creation de ressources si oui
        InterfaceCreeRessource *elementCreantRessource;
        elementCreantRessource = dynamic_cast<InterfaceCreeRessource*>(elementJoueurPourInfo);
        if (elementCreantRessource) {
            int bois=0;
            int nourriture=0;
            int _or=0;
            elementCreantRessource->ressourceParTour(bois,nourriture,_or);


            std::string boisString = std::to_string(bois);
            std::string nourritureString = std::to_string(nourriture);
            std::string orString = std::to_string(_or);

            nombreDegat->setString("\nCreation de ressources :\n"+boisString+" bois/tour\n"+nourritureString+" nourriture/tour\n"+orString+" or/tour"); 
        }

        
    }

}


void Dashboard::initInfo() {
    int current_x=ORIGINE_INFO_X;
    int current_y=ORIGINE_INFO_Y;

    // ---INFO ELEMENT---



    // PARTIE GAUCHE DASHBOARD

    // init nom_element_info
    nom_element_info = new TextForUI(COUCHE+1,false,""); 
    nom_element_info->setPosition(sf::Vector2f(current_x,current_y));
    nom_element_info->setFillColor(sf::Color::Black);
    nom_element_info->setCharacterSize(CHARACTER_SIZE_NOM);
    float lineSpacing = nom_element_info->getFont()->getLineSpacing(nom_element_info->getCharacterSize());

    // init icon_element_info
    current_y+=lineSpacing;
    icon_element_info = new AffichableOnPanel(Pixel(current_x,current_y),COUCHE+1,UserInterface::TRANSPARENCY_TEXTURE_NAME);

    // init vie_element_info
    current_y+=TAILLE_CARRE;
    vie_element_info = new TextForUI(COUCHE+1,false,""); 
    vie_element_info->setPosition(sf::Vector2f(current_x,current_y));
    vie_element_info->setFillColor(sf::Color::Black);
    vie_element_info->setCharacterSize(CHARACTER_SIZE_INFO_ELEMENT);
    lineSpacing = vie_element_info->getFont()->getLineSpacing(vie_element_info->getCharacterSize());

    // init tour_element_info
    current_y+=lineSpacing;
    tour_element_info = new TextForUI(COUCHE+1,false,""); 
    tour_element_info->setPosition(sf::Vector2f(current_x,current_y));
    tour_element_info->setFillColor(sf::Color::Black);
    tour_element_info->setCharacterSize(CHARACTER_SIZE_INFO_ELEMENT);
    lineSpacing = tour_element_info->getFont()->getLineSpacing(tour_element_info->getCharacterSize());

    // init nombre_case_deplacement
    current_y+=lineSpacing;
    nombre_case_deplacement = new TextForUI(COUCHE+1,false,""); 
    nombre_case_deplacement->setPosition(sf::Vector2f(current_x,current_y));
    nombre_case_deplacement->setFillColor(sf::Color::Black);
    nombre_case_deplacement->setCharacterSize(CHARACTER_SIZE_INFO_ELEMENT);
    lineSpacing = nombre_case_deplacement->getFont()->getLineSpacing(nombre_case_deplacement->getCharacterSize());



    // PARTIE DROITE DASHBOARD

    current_x=ORIGINE_INFO_PARTIE_2_X;
    current_y=ORIGINE_INFO_Y+nom_element_info->getFont()->getLineSpacing(nom_element_info->getCharacterSize());;

    // init nombreDegat
    nombreDegat = new TextForUI(COUCHE+1,false,""); 
    nombreDegat->setPosition(sf::Vector2f(current_x,current_y));
    nombreDegat->setFillColor(sf::Color::Black);
    nombreDegat->setCharacterSize(CHARACTER_SIZE_INFO_ELEMENT);
    lineSpacing = nombreDegat->getFont()->getLineSpacing(nombreDegat->getCharacterSize());  

    // init distanceAttaque
    current_y+=lineSpacing;
    distanceAttaque = new TextForUI(COUCHE+1,false,"\n\n"); 
    distanceAttaque->setPosition(sf::Vector2f(current_x,current_y));
    distanceAttaque->setFillColor(sf::Color::Black);
    distanceAttaque->setCharacterSize(CHARACTER_SIZE_INFO_ELEMENT);
    lineSpacing = distanceAttaque->getFont()->getLineSpacing(distanceAttaque->getCharacterSize()); 
     
    // init creationRessource
    current_y+=lineSpacing;
    creationRessource = new TextForUI(COUCHE+1,false,"\n\n\n"); 
    creationRessource->setPosition(sf::Vector2f(current_x,current_y));
    creationRessource->setFillColor(sf::Color::Black);
    creationRessource->setCharacterSize(CHARACTER_SIZE_INFO_ELEMENT);
    lineSpacing = distanceAttaque->getFont()->getLineSpacing(distanceAttaque->getCharacterSize());      





    // ---INFO NORMAL---

    // init info_normal
    info_normal = new TextForUI(COUCHE+1,false,""); 
    info_normal->setPosition(sf::Vector2f(ORIGINE_INFO_X,ORIGINE_INFO_Y));
    info_normal->setFillColor(sf::Color::Black);
    info_normal->setCharacterSize(CHARACTER_SIZE_INFO);

}


void Dashboard::removeInfoElement() {
    this->elementJoueurPourInfo=nullptr;
    updateInfoElement();
}

void Dashboard::pushCommandes(ListPtrCommandeSquare_ptr commandes, std::string info) {

    removeInfoElement();

    pushInfos(info);

    pushCommandeSquare(commandes); 



}

void Dashboard::removeInfoNormal() {
    info_normal->setString("");
}


void Dashboard::pushInfos(std::string info) {
    removeInfoElement();
    info_normal->setString(info);
}


void Dashboard::removeCommande(CommandeSquare* commande) {
    commandesSquare.remove(commande);
    delete commande;
}



void Dashboard::clearAll() {
    removeInfoNormal();
    removeInfoElement();
    cleanCommandeSquare();
}
