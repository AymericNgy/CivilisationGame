#include "case.hpp"
#include "AffichableOnMap/terrain.hpp"
#include "plateau.hpp"
#include <iostream>
#include "Commande/commande_square.hpp"
#include "AffichableOnMap/element_joueur.hpp"
#include "Commande/select_specific_element.hpp"
#include "jeu.hpp"
#include "hud.hpp"
#include "AffichableOnMap/caserne.hpp"
#include "UserInterface/affichable_on_map.hpp"
#include "Commande/acheter_case.hpp"
#include "joueur.hpp"
#include "Commande/creer_element.hpp"

// ---Case---

Case::Case(CasePosition casePosition, Plateau &plateau)
{

    this->casePosition = casePosition;
}

Case::~Case()
{
}

std::set<AffichableOnMap *> &Case::getElementsOn()
{
    return elementsOn;
}

void Case::_commandeSelectElement()
{

    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    ElementJoueur *elementJoueur;

    Joueur_ptr joueur_actif = Jeu::getInstance().getJoueurActif();
    if (nombreElementJoueurOn(joueur_actif) == 1)
    { // on execute directement la commande
        for (AffichableOnMap *element : elementsOn)
        {
            elementJoueur = dynamic_cast<ElementJoueur *>(element);
            if (elementJoueur)
            { // teste si element est bien un ElementJoueur*
                if (elementJoueur->getJoueurProprietaire()==joueur_actif) {
                    SelectSpecificElement commandeSelect(elementJoueur);
                    commandeSelect.execute();
                    break;
                }
            }
        }
    }
    else
    {
        for (AffichableOnMap *element : elementsOn)
        {
            elementJoueur = dynamic_cast<ElementJoueur *>(element);
            if (elementJoueur)
            { // teste si element est bien un ElementJoueur*
                if (elementJoueur->getJoueurProprietaire()==joueur_actif) {
                    commandes->push_back(new SelectSpecificElement(elementJoueur));
                }
                
            }
        }

        Jeu::getInstance().getHud().pushCommandes(commandes, "selectionnez un element");
    }
}

void Case::_commandeAcheterCase()
{
    setProprietaire(Jeu::getInstance().getJoueurActif());
}

void Case::_commandeConstuire()
{
    // [!] AUGMENTER AU FUR ET A MESURE QUE DES NOUVEAUX BATIMENTS SONT DISPONIBLES

    ListPtrCommandeSquare_ptr commandes = std::make_shared<std::list<CommandeSquare *>>();
    commandes->push_back(new CreerElement<Caserne>(getPosition(),Jeu::getInstance().getJoueurActif(),nullptr));
    Jeu::getInstance().getHud().pushCommandes(commandes,"choississez un batiment a construire");
}

int Case::nombreElementJoueurOn()
{
    ElementJoueur *elementJoueur;

    int nombreElementJoueur = 0;

    for (AffichableOnMap *element : elementsOn)
    {
        elementJoueur = dynamic_cast<ElementJoueur *>(element);
        if (elementJoueur)
        { // teste si element est bien un ElementJoueur*
            nombreElementJoueur++;
        }
    }
    return nombreElementJoueur;
}

int Case::nombreElementJoueurOn(Joueur_ptr joueur)
{
    ElementJoueur *elementJoueur;

    int nombreElementJoueur = 0;

    for (AffichableOnMap *element : elementsOn)
    {
        elementJoueur = dynamic_cast<ElementJoueur *>(element);
        if (elementJoueur)
        { // teste si element est bien un ElementJoueur*
            if (elementJoueur->getJoueurProprietaire()==joueur) {
                nombreElementJoueur++;
            }
        }
    }
    return nombreElementJoueur;
}

void Case::setProprietaire(Joueur_ptr proprietaire)
{
    this->proprietaire = proprietaire;
    Jeu::getInstance().getPlateau().updateMarqueProprietaire();
}

bool Case::batimentsOn() {
    Batiment *batiment;


    for (AffichableOnMap *element : elementsOn)
    {
        batiment = dynamic_cast<Batiment *>(element);
        if (batiment) { // teste si element est un batiment
            return true;
        }
    }
    return false;
}












// ---CasePosition---

bool CasePosition::operator<(const CasePosition &other) const
{
    if (x < other.x)
    {
        return true;
    }
    else if (x == other.x)
    {
        return y < other.y;
    }
    else
    {
        return false;
    }
}

CasePosition &CasePosition::operator=(const CasePosition &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const CasePosition &case_)
{
    os << "(" << case_.x << "," << case_.y << ")";
    return os;
}